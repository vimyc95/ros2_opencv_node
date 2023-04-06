## ROS2 OpenCV node
#
## Build example
    mkdir -p ~/ros2_ws/src
    cd ~/ros2_ws/src
    git clone https://github.com/vimyc95/ros2_opencv_node.git
    cd ~/ros2_ws
    colcon build
## Run node
### Camera https://github.com/IntelRealSense/realsense-ros.git
### Device: D435i
    ros2 launch realsense2_camera rs_launch.py

### Subscribe topic :
### &ensp;&ensp;&ensp;/camera/color/image_raw
    ros2 run cv_node image_sub_loop.cpp

