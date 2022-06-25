

라이다 사용 시 reference="lidar_1" 꼭 붙여야 한다.

```
<gazebo reference="lidar_1">
  <sensor name="lidar" type="ray">
    <pose>0 0 0 0 0 0</pose>
    <always_on>true</always_on>
    <visualize>false</visualize>
    <update_rate>10</update_rate>
    <ray>
```

imu 

https://github.com/ros-simulation/gazebo_ros_pkgs/wiki/ROS-2-Migration:-IMU-Sensors

```
[async_slam_toolbox_node-1] [INFO] [map_io]: Writing map occupancy data to /home/kimsooyoung/djhrd_ws/src/djhrd_ros2/maze.pgm
[async_slam_toolbox_node-1] [INFO] [map_io]: Writing map metadata to /home/kimsooyoung/djhrd_ws/src/djhrd_ros2/maze.yaml
[async_slam_toolbox_node-1] [INFO] [map_io]: Map saved
[async_slam_toolbox_node-1] [INFO] [1656139660.748566200] [map_saver]: Map saved successfully
[async_slam_toolbox_node-1] [INFO] [1656139660.748704100] [map_saver]: Destroying
```