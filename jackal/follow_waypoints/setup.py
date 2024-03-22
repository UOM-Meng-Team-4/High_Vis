from setuptools import find_packages, setup

package_name = 'follow_waypoints'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='angusmuir',
    maintainer_email='angus.muir@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'follow_waypoints_exe = follow_waypoints.follow_waypoints:main',
            'nav_through_posess_exe = follow_waypoints.nav_through_posess:main'
        ],
    },
)
