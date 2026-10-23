#!/usr/bin/env python3
"""
try_refinement.py -- test the LLM refinement without running ROS.

Runs each instruction through the same two steps as the real system:
  1. generate_transform()  (llm_interface_node)   -> asks Gemini for a 30-point shape
  2. run_transform() + apply_transform()  (llm_interface_node + coords_adjust_node)
     -> runs the code in the restricted runner, then clamps and resamples the shape
and prints pass/fail (a pass means a usable shape came back; spacing and
drone count are NOT checked, the planning pipeline does that later), time
taken, and how the shape changed. Results are also saved to
llm_test_results.csv, and a picture of every case (current shape in grey,
proposed shape in blue, unusable reply in red) to llm_test_results.png.

Run it from the folder that contains llm_interface_node.py and
coords_adjust_node.py (or after `source install/setup.bash`):

    export GEMINI_API_KEY=...
    python3 try_refinement.py                 # built-in instruction list
    python3 try_refinement.py "make it wider"  # or your own instruction(s)
"""

import csv
import json
import math
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
try:
    from llm_interface_node import generate_transform, run_transform, CodeError, resolve_colour
    from coords_adjust_node import apply_transform, TransformError, BOUNDARY_X, BOUNDARY_Y
except ImportError:
    from llm_refinement.llm_interface_node import (generate_transform, run_transform, CodeError,
                                                   resolve_colour)
    from llm_refinement.coords_adjust_node import (apply_transform, TransformError,
                                                   BOUNDARY_X, BOUNDARY_Y)

MODEL = os.environ.get('LLM_MODEL', 'gemini-3.5-flash-lite')
TIMEOUT = 30.0     # generous for testing; the node's llm_timeout_s default is 12 s

# 8 points on a ring: radius 0.9 m, centred at (0, 1.5)
SHAPE = [(0.9 * math.cos(2 * math.pi * k / 8), 1.5 + 0.9 * math.sin(2 * math.pi * k / 8))
         for k in range(8)]
# two colours, like a two-colour drawing: first half red (index 0), second half blue (index 1)
PALETTE = [(1.0, 0.0, 0.0, 1.0), (0.0, 0.0, 1.0, 1.0)]
COLORS = [0] * 4 + [1] * 4

INSTRUCTIONS = [
    'make it bigger',
    'make it smaller',
    'move it to the left',
    'move it up',
    'rotate it 90 degrees',
    'make it twice as wide',
    'flip it upside down',
    'make it 3 times bigger',            # should be limited to stay inside the boundary
    'squash it flat vertically',         # tests the spacing rule
    'shift it right until it touches the edge',
    'make the top half wider than the bottom half',
    'turn it into a square',
]


def describe(points):
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    return (sum(xs) / len(xs), sum(ys) / len(ys), max(xs) - min(xs), max(ys) - min(ys))


def plot_results(rows, path='llm_test_results.png', cols=4):
    import matplotlib
    import matplotlib.pyplot as plt
    from matplotlib.patches import Rectangle

    n = len(rows)
    nrows = math.ceil(n / cols)
    fig, axes = plt.subplots(nrows, cols, figsize=(4.2 * cols, 3.6 * nrows), squeeze=False)
    for ax in axes.flat[n:]:
        ax.axis('off')

    for ax, r in zip(axes.flat, rows):
        ax.add_patch(Rectangle((BOUNDARY_X[0], BOUNDARY_Y[0]),
                               BOUNDARY_X[1] - BOUNDARY_X[0], BOUNDARY_Y[1] - BOUNDARY_Y[0],
                               fill=False, ls='--', lw=1, ec='#888888'))
        ax.scatter([p[0] for p in SHAPE], [p[1] for p in SHAPE],
                   c=[PALETTE[c][:3] for c in COLORS], s=60, alpha=0.3, zorder=1)  # current shape
        out = r['output']
        colour = '#1f77b4' if r['passed'] else '#d62728'
        if out:
            ax.plot([p[0] for p in out], [p[1] for p in out], '-', color=colour, lw=0.6,
                    alpha=0.5, zorder=2)                     # stroke order
            for i, (x, y) in enumerate(out):
                cols = r.get('out_colors')
                ax.plot(x, y, 'o', color=cols[i][:3] if cols else colour, ms=4, zorder=3)
                if i % 5 == 0:
                    ax.annotate(str(i), (x, y), fontsize=6, xytext=(2, 2),
                                textcoords='offset points')
        else:
            ax.text(0, 1.5, 'no output', ha='center', color=colour)
        ax.set_xlim(BOUNDARY_X[0] - 0.4, BOUNDARY_X[1] + 0.4)
        ax.set_ylim(BOUNDARY_Y[0] - 0.3, BOUNDARY_Y[1] + 0.3)
        ax.set_aspect('equal')
        ax.tick_params(labelsize=6)
        head = ('PASS  ' if r['passed'] else 'FAIL  ') + r['instruction']
        ax.set_title(head, fontsize=8, color=colour, loc='left')
        if not r['passed']:
            ax.set_xlabel(r['reason'][:70], fontsize=6, color=colour)

    fig.suptitle(f'LLM refinement test ({MODEL}); grey = current shape, line = stroke order '
                 f'of the proposed points (every 5th numbered)', fontsize=9)
    fig.tight_layout()
    fig.savefig(path, dpi=130)
    print(f'saved {path}')
    try:
        if matplotlib.get_backend().lower() != 'agg':
            plt.show()
    except Exception:                                        # noqa: BLE001
        pass


def run(instruction):
    t0 = time.time()
    try:
        plan, code, _ = generate_transform(instruction, SHAPE, MODEL, TIMEOUT,
                                             colors=COLORS, palette=PALETTE)
    except Exception as exc:                                    # noqa: BLE001
        return dict(instruction=instruction, stage='llm', passed=False,
                    reason=f'{type(exc).__name__}: {exc}', seconds=time.time() - t0,
                    plan='', points='', change='', output=None)
    t_llm = time.time() - t0

    # Run the generated code exactly as llm_interface_node does (restricted)
    try:
        proposed = run_transform(code, SHAPE, COLORS)
    except CodeError as exc:
        return dict(instruction=instruction, stage='execution', passed=False,
                    reason=str(exc), seconds=t_llm,
                    plan=plan, points='', change='', output=None)

    points_json = json.dumps([[round(x, 3), round(y, 3), c] for x, y, c in proposed])
    try:
        rgba = [resolve_colour(c, PALETTE) for _, _, c in proposed]
        out, out_cols = apply_transform(proposed, SHAPE,
                                        labels=rgba if all(rgba) else None) \
            if all(rgba) else (apply_transform(proposed, SHAPE), None)
    except TransformError as exc:
        return dict(instruction=instruction, stage='checks', passed=False, reason=str(exc),
                    seconds=t_llm, plan=plan, points=points_json, change='', output=None)
    c0, c1 = describe(SHAPE), describe(out)
    change = (f'{len(out)} points; centre moved ({c1[0] - c0[0]:+.2f}, {c1[1] - c0[1]:+.2f}) m; '
              f'width {c0[2]:.2f}->{c1[2]:.2f}, height {c0[3]:.2f}->{c1[3]:.2f}')
    return dict(instruction=instruction, stage='ok', passed=True, reason='',
                seconds=t_llm, plan=plan, points=points_json, change=change, output=out,
                out_colors=out_cols)


def main():
    instructions = sys.argv[1:] or INSTRUCTIONS
    rows = []
    for ins in instructions:
        r = run(ins)
        rows.append(r)
        mark = 'PASS' if r['passed'] else 'FAIL'
        print(f"[{mark}] {ins!r}  ({r['seconds']:.1f}s)")
        if r['passed']:
            print(f"       {r['plan']}\n       {r['change']}")
        else:
            print(f"       failed at {r['stage']}: {r['reason']}")
            if r['points']:
                print('       --- proposed points ---')
                print('       ' + r['points'])
        time.sleep(1.0)    # stay well under the free-tier requests-per-minute limit

    n_ok = sum(r['passed'] for r in rows)
    secs = sorted(r['seconds'] for r in rows)
    print(f'\n{n_ok}/{len(rows)} passed; median {secs[len(secs) // 2]:.1f}s, slowest {secs[-1]:.1f}s '
          f'(test timeout {TIMEOUT:.0f}s)')

    with open('llm_test_results.csv', 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=['instruction', 'passed', 'stage', 'reason',
                                          'seconds', 'plan', 'change', 'points'])
        w.writeheader()
        w.writerows({k: v for k, v in r.items() if k not in ('output', 'out_colors')} for r in rows)
    print('saved llm_test_results.csv')
    plot_results(rows)


if __name__ == '__main__':
    main()
