from setuptools import find_packages, setup

package_name = 'cam_topic'

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
            "cam_top_pub = cam_topic.camera_topic:main",
            "cam_top_pub_visual = cam_topic.camera_topic_visual:main",
            "cam_top_sub = cam_topic.camera_topic_sub:main",

        ],
    },
)
