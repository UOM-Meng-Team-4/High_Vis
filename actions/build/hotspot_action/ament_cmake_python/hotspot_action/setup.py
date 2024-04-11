from setuptools import find_packages
from setuptools import setup

setup(
    name='hotspot_action',
    version='0.0.0',
    packages=find_packages(
        include=('hotspot_action', 'hotspot_action.*')),
)
