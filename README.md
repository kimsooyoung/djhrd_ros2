# djhrd_ros2

```
cbp fusionbot_description && rosfoxy
cbp fusionbot_gazebo && rosfoxy
cbp fusionbot_slam && rosfoxy
cbp fusionbot_amcl && rosfoxy
cbp fusionbot_nav && rosfoxy
```

```
ros2 launch fusionbot_description fusionbot_description.launch.py
ros2 launch fusionbot_description fusionbot_gazebo.launch.py

# 이후 원하는 위치에 빌딩 추가
ros2 launch fusionbot_gazebo make_my_world.launch.py

# custom world launch
ros2 launch fusionbot_gazebo run_my_world.launch.py
```

```
# slam
ros2 launch fusionbot_gazebo run_my_world.launch.py
ros2 launch fusionbot_slam gazebo_slam_toolbox.launch.py

# amcl
ros2 launch fusionbot_amcl amcl.launch.py

# nav2
ros2 launch fusionbot_nav bringup_launch.py

# caffee world
# urdf 마찰 수정해야 함
ros2 launch fusionbot_gazebo caffee_world.launch.py
```



sudo apt install ros-foxy-gazebo-ros-pkgs
sudo apt install ros-foxy-slam-toolbox

![image](https://user-images.githubusercontent.com/12381733/175758221-a84f39b5-68e9-4add-bcd3-a987234bf6b0.png)

[] 여러 가제보 object 추가하는거 할까 말까
[] Docker로 하면서 처음부터 패키지 전부 조사
[] 필요없는 코드 모두 지우기
[] 



강의 전 조사

ROS에 대해 안다.
Gazebo에 대해 안다.
ROS 2에 대해 안다.
ROS 2의 topic에 대해 안다.
ROS 2의 launch file에 대해 안다.
ROS 2의 nav2에 대해 안다.