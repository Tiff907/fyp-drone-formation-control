"""
llm_interface_node.py

Turns a natural-language refinement instruction into a small Python
function using an LLM, runs that function on the current points, and
publishes the resulting shape for coords_adjust_node to clean up.

    /refinement/command (RefinementCmd) -> LLM -> run the code
        -> /refinement/generated_transform (GeneratedTransform, with proposed_points)

The LLM's code is untrusted, so it is run with limits: a whitelist of Python
syntax (no imports, no while loops, no dunder names, only `math.` and plain
list methods such as .append), restricted builtins, a separate process, a time
limit and a memory limit. This stops ordinary mistakes (typos, runaway loops);
it is not a hardened sandbox against a deliberately hostile program.

The only place that talks to a specific LLM provider is call_llm(). It uses
Google's Gemini API through its OpenAI-compatible endpoint, with the Python
standard library only (nothing to pip install).

Setup:  export GEMINI_API_KEY=...        (key from aistudio.google.com)
Optional environment variables:
    LLM_BASE_URL          another OpenAI-compatible provider (Groq, Cerebras, ...)
    LLM_REASONING_EFFORT  'low' (default), 'medium', 'high', or '' to omit
"""

import ast
import json
import math
import multiprocessing as mp
import os
import re
import resource
import time

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

from formation_msgs.msg import RefinementCmd, GeneratedTransform, PlanStatus


SYSTEM_PROMPT = """You edit a drone formation by writing one short Python function.

Coordinates are metres on the canvas: x is left-right in [-2.5, 2.5], y is
HEIGHT in [0, 3]. You receive the user's instruction and the current points
in order. Every point is (x, y, c): c is the index of its colour in the
palette that is given with the points.

Reply in exactly this format and nothing else:

PLAN: <one sentence saying what the function does>
```python
def transform(points):
    # points: list of (x, y, c) tuples
    # return a list of (x, y, c) tuples
    ...
```

Rules:
- Colours: every returned point needs a colour c. Keep each point's own colour
  when you move, scale or copy it (new points between two points take the
  colour of one of them). Only change colours if the user asks; use a palette
  index, or a hex string such as "#ff0000" for a colour not in the palette.
- Return the new shape as an ordered outline, as many points as you need. Include every corner. For a closed shape, end near the start.
- Every point must stay inside x in [-2.5, 2.5] and y in [0, 3]. When
  scaling or moving, limit the amount so the whole shape stays inside.
- Use only plain Python and the `math` module (already available as `math`).
  No imports, no while loops, no file or network access, no classes, no type
  hints. You may call list methods such as .append.
- Scaling, rotating and mirroring are done about the shape's centroid unless
  the user says otherwise. "Up" means larger y. "Left" means smaller x.
- If the instruction cannot be followed within these rules, do the closest
  valid version and say what you changed in PLAN.
"""


MAX_PALETTE = 12

_COLOUR_NAMES = {
    'red': (1, 0, 0), 'orange': (1, .55, .15), 'yellow': (1, .85, .2),
    'green': (0, .7, .25), 'light green': (.47, .85, .34), 'cyan': (0, .8, .8),
    'blue': (.14, .06, .72), 'purple': (.7, .3, .85), 'pink': (1, .5, .75),
    'brown': (.5, .3, .1), 'black': (0, 0, 0), 'grey': (.5, .5, .5),
    'white': (1, 1, 1),
}


def colour_name(rgb):
    return min(_COLOUR_NAMES, key=lambda k: sum((a - b) ** 2 for a, b in zip(_COLOUR_NAMES[k], rgb)))


def hex_to_rgb(text):
    m = re.fullmatch(r'#?([0-9a-fA-F]{6})', str(text).strip())
    if not m:
        return None
    h = m.group(1)
    return tuple(int(h[i:i + 2], 16) / 255 for i in (0, 2, 4))


def make_palette(colors):
    """colors: one (r, g, b, a) per point (or None). Returns (palette, index
    per point): palette is a list of (r, g, b, a) without repeats, index
    refers to it. More than MAX_PALETTE distinct colours: extras take the
    nearest earlier one."""
    palette, idx = [], []
    for c in colors:
        c = tuple(round(float(v), 3) for v in c)
        if c in palette:
            idx.append(palette.index(c))
        elif len(palette) < MAX_PALETTE:
            palette.append(c)
            idx.append(len(palette) - 1)
        else:
            idx.append(min(range(len(palette)),
                           key=lambda i: sum((a - b) ** 2 for a, b in zip(palette[i][:3], c[:3]))))
    return palette, idx


def resolve_colour(c, palette):
    """Turn what the generated code returned (palette index, hex string or
    None) into (r, g, b, a), or None if it cannot be understood."""
    if isinstance(c, bool) or c is None:
        return None
    if isinstance(c, (int, float)):
        i = int(round(c))
        return palette[i] if 0 <= i < len(palette) else None
    rgb = hex_to_rgb(c)
    return (*rgb, 1.0) if rgb else None


def build_user_prompt(instruction, points, colors=None, palette=None):
    """points: list of (x, y); colors: palette index per point (or None)."""
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    if colors is not None and palette:
        pts = [[round(x, 3), round(y, 3), int(c)] for (x, y), c in zip(points, colors)]
        legend = 'Palette (index = colour): ' + ', '.join(
            f'{i} = {colour_name(c[:3])} #{round(c[0] * 255):02x}{round(c[1] * 255):02x}{round(c[2] * 255):02x}'
            for i, c in enumerate(palette)) + '\n'
    else:
        pts = [[round(x, 3), round(y, 3), 0] for x, y in points]
        legend = 'Palette (index = colour): 0 = one colour for the whole shape\n'
    return (
        f'Instruction: {instruction}\n\n'
        f'Number of points: {len(points)}\n'
        f'Bounding box: x {min(xs):.2f}..{max(xs):.2f}, y {min(ys):.2f}..{max(ys):.2f}\n'
        f'{legend}'
        f'Points (x, y, colour index): {json.dumps(pts)}'
    )


def parse_reply(text):
    """Returns (plan_description, code). Raises ValueError if no code."""
    m = re.search(r'```(?:python)?\s*\n(.*?)```', text, re.DOTALL)
    if m:
        code = m.group(1).strip()
    elif 'def transform' in text:
        code = text[text.index('def transform'):].strip()
    else:
        raise ValueError('No code block in LLM reply')
    p = re.search(r'PLAN:\s*(.+)', text)
    plan = p.group(1).strip() if p else 'LLM refinement'
    return plan, code


# ---------------------------------------------------------------------
# Running the generated code (restricted)
# ---------------------------------------------------------------------

class CodeError(Exception):
    """The generated code was rejected or failed when run."""


EXEC_TIMEOUT_S = 2.0
MEMORY_LIMIT_BYTES = 512 * 1024 * 1024
MAX_CODE_CHARS = 4000

_ALLOWED_NODES = (
    ast.Module, ast.FunctionDef, ast.arguments, ast.arg, ast.Return,
    ast.Assign, ast.AugAssign, ast.Expr, ast.For, ast.If, ast.Pass,
    ast.Break, ast.Continue, ast.IfExp, ast.ListComp, ast.GeneratorExp,
    ast.comprehension, ast.BinOp, ast.UnaryOp, ast.BoolOp, ast.Compare,
    ast.Call, ast.keyword, ast.Attribute, ast.Subscript, ast.Slice,
    ast.Name, ast.Constant, ast.Tuple, ast.List, ast.Lambda,
    ast.operator, ast.unaryop, ast.cmpop, ast.boolop, ast.expr_context,
)
_LIST_METHODS = {'append', 'extend', 'insert', 'pop', 'sort', 'reverse', 'index', 'count', 'copy'}
_SAFE_BUILTINS = {
    'abs': abs, 'min': min, 'max': max, 'sum': sum, 'len': len,
    'range': range, 'enumerate': enumerate, 'zip': zip, 'sorted': sorted,
    'round': round, 'float': float, 'int': int, 'list': list,
    'tuple': tuple, 'reversed': reversed, 'any': any, 'all': all,
}


def validate_code(code):
    if not isinstance(code, str) or not code.strip():
        raise CodeError('No code received')
    if len(code) > MAX_CODE_CHARS:
        raise CodeError('Generated code too long')
    try:
        tree = ast.parse(code)
    except SyntaxError as exc:
        raise CodeError(f'Syntax error in generated code: {exc.msg}')

    for node in ast.walk(tree):                 # type hints would be evaluated and fail
        if isinstance(node, ast.FunctionDef):
            node.returns = None
            for a in node.args.args:
                a.annotation = None

    for stmt in tree.body:
        if not isinstance(stmt, (ast.FunctionDef, ast.Assign)):
            raise CodeError('Only function definitions and constants are allowed at top level')
    for node in ast.walk(tree):
        if not isinstance(node, _ALLOWED_NODES):
            raise CodeError(f'Disallowed syntax: {type(node).__name__}')
        if isinstance(node, ast.Name) and node.id.startswith('__'):
            raise CodeError(f'Disallowed name: {node.id}')
        if isinstance(node, ast.Attribute):
            is_math = (isinstance(node.value, ast.Name) and node.value.id == 'math'
                       and not node.attr.startswith('_'))
            if not (is_math or node.attr in _LIST_METHODS):
                raise CodeError(f'Attribute .{node.attr} is not allowed')
    fns = [s for s in tree.body if isinstance(s, ast.FunctionDef) and s.name == 'transform']
    if len(fns) != 1 or len(fns[0].args.args) != 1:
        raise CodeError('Code must define exactly one function: transform(points)')
    return tree


def _clean_colour(c):
    if isinstance(c, bool):
        return None
    if isinstance(c, (int, float)):
        return int(round(c)) if math.isfinite(c) else None
    return c[:16] if isinstance(c, str) else None


def _child(conn, tree, points):
    try:
        resource.setrlimit(resource.RLIMIT_AS, (MEMORY_LIMIT_BYTES, MEMORY_LIMIT_BYTES))
        env = {'__builtins__': _SAFE_BUILTINS, 'math': math}
        exec(compile(tree, '<generated>', 'exec'), env)
        out = env['transform']([tuple(p) for p in points])
        conn.send(('ok', [[float(p[0]), float(p[1]),
                           _clean_colour(p[2]) if len(p) > 2 else None] for p in out]))
    except BaseException as exc:                           # noqa: B902
        conn.send(('err', f'{type(exc).__name__}: {exc}'))
    finally:
        conn.close()


def run_transform(code, points, colors=None, timeout=EXEC_TIMEOUT_S):
    """Validate and run the generated code. points: (x, y) list; colors:
    palette index per point (optional). Returns a list of (x, y, c), where c
    is whatever colour the code gave the point (index, hex string) or None."""
    if colors is not None:
        points = [(x, y, c) for (x, y), c in zip(points, colors)]
    else:
        points = [(x, y, 0) for x, y in points]
    tree = validate_code(code)
    ctx = mp.get_context('fork')
    parent, child = ctx.Pipe(duplex=False)
    proc = ctx.Process(target=_child, args=(child, tree, points), daemon=True)
    proc.start()
    child.close()
    try:
        if not parent.poll(timeout):
            raise CodeError(f'Generated code did not finish within {timeout:.0f}s')
        kind, payload = parent.recv()
    except EOFError:
        raise CodeError('Generated code crashed (possibly out of memory)')
    finally:
        parent.close()
        proc.join(0.5)
        if proc.is_alive():
            proc.kill()
            proc.join()
    if kind == 'err':
        raise CodeError(f'Generated code raised {payload}')
    return [(x, y, c) for x, y, c in payload]


def call_llm(system, user, model, timeout):
    """The ONLY provider-specific function. Returns the reply text."""
    import urllib.error
    import urllib.request

    key = os.environ.get('GEMINI_API_KEY') or os.environ.get('LLM_API_KEY')
    if not key:
        raise RuntimeError('GEMINI_API_KEY is not set')
    base = os.environ.get(
        'LLM_BASE_URL', 'https://generativelanguage.googleapis.com/v1beta/openai')

    payload = {
        'model': model,
        'max_tokens': 4096,     # room for the model's own thinking as well as the code
        'messages': [{'role': 'system', 'content': system},
                     {'role': 'user', 'content': user}],
    }
    effort = os.environ.get('LLM_REASONING_EFFORT', 'low')
    if effort:
        payload['reasoning_effort'] = effort    # keeps replies fast

    req = urllib.request.Request(
        base.rstrip('/') + '/chat/completions',
        json.dumps(payload).encode(),
        {'Content-Type': 'application/json', 'Authorization': 'Bearer ' + key})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            data = json.load(resp)
    except urllib.error.HTTPError as exc:
        raise RuntimeError(f'HTTP {exc.code}: {exc.read().decode(errors="replace")[:200]}')
    return data['choices'][0]['message']['content'] or ''


def generate_transform(instruction, points, model, timeout, colors=None, palette=None,
                       llm=call_llm):
    """Pure function: usable from a plain script, no ROS needed. colors is a
    palette index per point, palette the list of (r, g, b, a) it refers to."""
    reply = llm(SYSTEM_PROMPT, build_user_prompt(instruction, points, colors, palette),
                model, timeout)
    plan, code = parse_reply(reply)
    return plan, code, reply


class LlmInterfaceNode(Node):

    def __init__(self):
        super().__init__('llm_interface_node')

        self.declare_parameter('llm_model', 'gemini-3.5-flash-lite')
        # Keep below task_manager's refinement_timeout_s (60 s).
        self.declare_parameter('llm_timeout_s', 45.0)
        self.declare_parameter('log_path', os.path.expanduser('~/llm_refinement_log.jsonl'))

        self.create_subscription(RefinementCmd, '/refinement/command', self._on_command, 10)
        self._pub = self.create_publisher(GeneratedTransform, '/refinement/generated_transform', 10)
        self._status_pub = self.create_publisher(PlanStatus, '/formation/plan_status', 10)

        self._check_msg_fields()
        self.get_logger().info('llm_interface_node started')

    def _check_msg_fields(self):
        """A formation_msgs build that predates the colour/proposal fields makes
        every refinement fail silently, so say so at start-up."""
        need = {RefinementCmd: ('current_colors',),
                GeneratedTransform: ('proposed_points', 'proposed_colors')}
        for cls, names in need.items():
            fields = getattr(cls, 'get_fields_and_field_types', lambda: None)()
            missing = [n for n in names if fields is not None and n not in fields]
            if missing:
                self.get_logger().error(
                    f'{cls.__name__} has no field(s) {missing}: add them to the .msg and '
                    'rebuild formation_msgs and the packages that use it')

    def _log(self, record):
        path = self.get_parameter('log_path').value
        if not path:
            return
        try:
            with open(path, 'a') as f:
                f.write(json.dumps(record) + '\n')
        except OSError as exc:
            self.get_logger().warn(f'Could not write log: {exc}')

    def _on_command(self, msg: RefinementCmd):
        try:
            self._handle_command(msg)
        except Exception as exc:                            # noqa: BLE001
            # An exception escaping a ROS callback is only logged, and the GUI
            # would just wait until its own timeout. Report it instead.
            self.get_logger().error(f'Unexpected error: {type(exc).__name__}: {exc}')
            self._fail(f'Refinement failed: {type(exc).__name__}: {str(exc)[:80]}')

    def _handle_command(self, msg: RefinementCmd):
        points = [(p.x, p.y) for p in msg.current_points]
        raw_colors = [(c.r, c.g, c.b, c.a) for c in msg.current_colors]
        if len(raw_colors) == len(points) and points:
            palette, colors = make_palette(raw_colors)
        else:                       # no usable colours: the shape is treated as one colour
            palette, colors = [], None
        record = {'stage': 'llm_interface', 'time': time.time(),
                  'instruction': msg.instruction_text, 'n': len(points),
                  'model': self.get_parameter('llm_model').value}
        if not points or not msg.instruction_text.strip():
            self._fail('Refinement request was empty')
            return

        t0 = time.time()
        try:
            plan, code, reply = generate_transform(
                msg.instruction_text, points,
                self.get_parameter('llm_model').value,
                float(self.get_parameter('llm_timeout_s').value),
                colors=colors, palette=palette)
        except Exception as exc:                            # noqa: BLE001
            record.update(ok=False, error=f'{type(exc).__name__}: {exc}',
                          seconds=time.time() - t0)
            self._log(record)
            self.get_logger().error(f'LLM call failed: {exc}')
            self._fail(f'LLM call failed: {type(exc).__name__}: {str(exc)[:80]}')
            return

        try:
            proposed = run_transform(code, points, colors)
        except CodeError as exc:
            record.update(ok=False, error=str(exc), plan=plan, code=code,
                          seconds=time.time() - t0)
            self._log(record)
            self.get_logger().error(f'Generated code rejected: {exc}')
            self._fail(f'Refinement code rejected: {str(exc)[:100]}')
            return

        record.update(ok=True, plan=plan, code=code, n_proposed=len(proposed),
                      seconds=time.time() - t0)
        self._log(record)

        out = GeneratedTransform()
        out.generated_code = code
        out.plan_description = plan
        out.current_points = [Point(x=x, y=y, z=0.0) for x, y in points]
        out.proposed_points = [Point(x=x, y=y, z=0.0) for x, y, _ in proposed]
        # Colours: only if the palette is known and every point got a valid one;
        # otherwise left empty and task_manager carries colours along the outline.
        rgba = [resolve_colour(c, palette) for _, _, c in proposed] if palette else []
        if rgba and all(rgba):
            out.proposed_colors = [ColorRGBA(r=r, g=g, b=b, a=a) for r, g, b, a in rgba]
        else:
            out.proposed_colors = []
        self._pub.publish(out)
        self.get_logger().info(f'Generated transform in {time.time() - t0:.1f}s: {plan}')

    def _fail(self, message):
        status = PlanStatus()
        status.success = False
        status.status_message = message
        status.usable_drone_count = 0
        self._status_pub.publish(status)


def main(args=None):
    rclpy.init(args=args)
    node = LlmInterfaceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
