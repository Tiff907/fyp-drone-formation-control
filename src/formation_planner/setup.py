from setuptools import find_packages, setup

package_name = 'formation_planner'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'scipy', 'visvalingamwyatt'],
    zip_safe=True,
    maintainer='tiffany',
    maintainer_email='tc20040709@gmail.com',
    description='Formation planning pipeline: shape sampling, coordinate mapping, drone validation, optimal assignment, and MAPF path planning',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'shape_sampling_node = formation_planner.shape_sampling_node:main',
            'coords_mapping_node = formation_planner.coords_mapping_node:main',
            'drone_validator_node = formation_planner.drone_validator_node:main',
            'assignment_node = formation_planner.assignment_node:main',
            'mapf_node = formation_planner.mapf_node:main',
        ],
    },
)
