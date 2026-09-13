from setuptools import find_packages
from setuptools import setup

setup(
    name='formation_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('formation_msgs', 'formation_msgs.*')),
)
