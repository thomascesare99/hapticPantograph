from setuptools import find_packages
from setuptools import setup

setup(
    name='ethercat_msgs',
    version='1.2.0',
    packages=find_packages(
        include=('ethercat_msgs', 'ethercat_msgs.*')),
)
