

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

카페 돌릴때는 마찰계수 수정해야 함

```
<gazebo reference="base_link">
  <material>${body_color}</material>
  <mu1>0.1</mu1>
  <mu2>0.1</mu2>
  <selfCollide>true</selfCollide>
  <gravity>true</gravity>
</gazebo>
```

수정 => 기존 urdf 삭제 => 
cbp fusionbot_description && rosfoxy
ros2 launch fusionbot_gazebo run_my_world.launch.py

turtlebot3 waffle 매개변수 참고 기존 것으로 하면 success가 나오질 않았음

https://github.com/ROBOTIS-GIT/turtlebot3/blob/foxy-devel/turtlebot3_navigation2/param/waffle.yaml

```
      # BaseObstacle.scale: 0.04
      # PathAlign.scale: 50.0
      # GoalAlign.scale: 10.0
      # PathAlign.forward_point_distance: 0.1
      # GoalAlign.forward_point_distance: 0.1
      # PathDist.scale: 50.0
      # GoalDist.scale: 0.0
      # RotateToGoal.scale: 32.0
      # RotateToGoal.slowing_factor: 5.0
      # RotateToGoal.lookahead_time: -1.0
      BaseObstacle.scale: 0.02
      PathAlign.scale: 32.0
      GoalAlign.scale: 24.0
      PathAlign.forward_point_distance: 0.1
      GoalAlign.forward_point_distance: 0.1
      PathDist.scale: 32.0
      GoalDist.scale: 24.0
      RotateToGoal.scale: 32.0
      RotateToGoal.slowing_factor: 5.0
      RotateToGoal.lookahead_time: -1.0
```



<link name="rplidar_a2">
  <inertial>
    <origin xyz="0.0034625894668202637 0.00010269753328175684 0.02092482852234422" rpy="0 0 0"/>
    <mass value="0.06839266167546813"/>
    <inertia ixx="3.8e-05" iyy="3.9e-05" izz="5.5e-05" ixy="0.0" iyz="-0.0" ixz="-2e-06"/>
  </inertial>
  <visual>
    <origin xyz="0 0 0" rpy="0 0 0"/>
    <geometry>
      <mesh filename="package://src_description/meshes/rplidar_a2.stl" scale="0.001 0.001 0.001"/>
    </geometry>
    <material name="silver"/>
  </visual>
  <collision>
    <origin xyz="0 0 0" rpy="0 0 0"/>
    <geometry>
      <mesh filename="package://src_description/meshes/rplidar_a2.stl" scale="0.001 0.001 0.001"/>
    </geometry>
  </collision>
</link>