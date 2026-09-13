from setuptools import find_packages, setup

package_name = 'formation_ui'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'websockets'],
    zip_safe=True,
    maintainer='tiffany',
    maintainer_email='tc20040709@gmail.com',
    description='Touchscreen canvas UI bridge: publishes drawn shapes and user commands, reflects system state and refinement candidates',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'canvas_server_node = formation_ui.canvas_server_node:main',
        ],
    },
)
