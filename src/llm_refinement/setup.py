from setuptools import find_packages, setup

package_name = 'llm_refinement'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'anthropic'],
    zip_safe=True,
    maintainer='tiffany',
    maintainer_email='tc20040709@gmail.com',
    description='Natural-language formation refinement: generates and executes Claude-produced code to transform a point set',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'llm_interface_node = llm_refinement.llm_interface_node:main',
            'coords_adjust_node = llm_refinement.coords_adjust_node:main',
        ],
    },
)
