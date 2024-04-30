from setuptools import find_packages, setup

package_name = 'actions_py'

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
    maintainer='harry',
    maintainer_email='harry.shakesheff@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "hotspot_server = actions_py.hotspot_server:main",
            "visual_cam_server = actions_py.visual_cam_server:main",
            "nav_server = actions_py.nav_server:main",
            "pt_server = actions_py.pt_server:main",
            "ac_server = actions_py.ac_server:main",
            "camera_topic_sub = actions_py.camera_topic_sub:main",
            "monitoring_client = actions_py.monitoring_client:main",
            "monitoring_client_before_integration = actions_py.monitoring_client_before_integration:main",
            "integration_executable = actions_py.integration_executable:main"
        ],
    },
)
