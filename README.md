# djhrd_ros2

대전정보문화산업징흥원 - ROS를 활용한 로봇 제어 및 자율주행 예제 코드

## 패키지 종속성 설치

```
./setup_scripts.sh
```

## 예제 패키지들 빌드

```
cbp fusionbot_description && rosfoxy
cbp fusionbot_gazebo && rosfoxy
cbp fusionbot_slam && rosfoxy
cbp fusionbot_amcl && rosfoxy
cbp fusionbot_nav && rosfoxy
```

## 예제 실행 

* Robot Description

<p align="center">
    <img src="https://user-images.githubusercontent.com/12381733/175823998-2fd274bf-3301-41c4-96e4-6b78030f599b.png" height="250">
</p>

```
ros2 launch fusionbot_description fusionbot_description.launch.py
ros2 launch fusionbot_description fusionbot_gazebo.launch.py
```

* Gazebo with Robot

```
# 자신만의 건물 제작 이후 원하는 위치에 빌딩 추가
ros2 launch fusionbot_gazebo make_my_world.launch.py

# custom world를 반영한 launch
ros2 launch fusionbot_gazebo run_my_world.launch.py
```

* Navigation - SLAM

<p align="center">
    <img src="https://user-images.githubusercontent.com/12381733/175824225-fc356a82-7684-4e4d-9c87-96788711ed94.png" height="250">
</p>

```
# slam
ros2 launch fusionbot_gazebo run_my_world.launch.py
ros2 launch fusionbot_slam gazebo_slam_toolbox.launch.py
```

* Navigation - AMCL

```
# amcl
ros2 launch fusionbot_gazebo run_my_world.launch.py
ros2 launch fusionbot_amcl amcl.launch.py
```

* Navigation - Maze

```
# nav2
ros2 launch fusionbot_gazebo run_my_world.launch.py
ros2 launch fusionbot_nav bringup_launch.py
```

* Navigation - Cafe World

<p align="center">
    <img src="https://user-images.githubusercontent.com/12381733/175822852-f78a9999-352a-4e30-86b9-bd1a06d0ecf2.png" height="250">
</p>


```
# caffee world
ros2 launch fusionbot_gazebo caffee_world.launch.py
ros2 launch fusionbot_nav bringup_cafe_launch.py
```

