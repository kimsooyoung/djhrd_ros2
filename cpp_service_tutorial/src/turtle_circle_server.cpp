// Copyright 2022 @RoadBalance
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <cstdlib>
#include <memory>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include "geometry_msgs/msg/twist.hpp"

static double MOVING_TIME = 5.0;

using SetBool = std_srvs::srv::SetBool;
using Twist = geometry_msgs::msg::Twist;

/**
 * std_srvs::srv::SetBool Description
 * 
 * bool data # e.g. for hardware enabling / disabling
 * --- 
 * bool success   # indicate successful run of triggered service 
 * string message # informational, e.g. for error messages
 */

class TurtleCircleNode : public rclcpp::Node {
private:
  rclcpp::Service<SetBool>::SharedPtr bool_client;
  rclcpp::Publisher<Twist>::SharedPtr twist_publisher;

  Twist twist_msg = geometry_msgs::msg::Twist();

  void turtle_circle(){
    twist_msg.linear.x = 2.0;
    twist_msg.angular.z = 1.0;

    auto t_start = this->now();
    auto t_now = this->now();

    while ((t_now - t_start).seconds() < MOVING_TIME) {
      t_now = this->now();
      twist_publisher->publish(twist_msg);
      RCLCPP_INFO(this->get_logger(), "%f Seconds Passed", (t_now - t_start).seconds());
    }

    twist_msg.linear.x = 0.0;
    twist_msg.angular.z = 0.0;

    twist_publisher->publish(twist_msg);
  }

  void server_callback(const std::shared_ptr<SetBool::Request> request,
                      const std::shared_ptr<SetBool::Response> response){

    if (request->data) {
      turtle_circle();
    }

    response->success = true;
    response->message = "Turtle successfully drawed Circle";
  }

public:
  TurtleCircleNode() : Node("turtle_circle_server"){
    
    bool_client = this->create_service<SetBool>(
      "turtle_circle",
      server_callback
    );
    RCLCPP_INFO(this->get_logger(), "Turtle Turning Server Started, Waiting for Request...");
  
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<TurtleCircleNode>();
  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}