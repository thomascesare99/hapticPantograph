// Copyright 2022, ICube Laboratory, University of Strasbourg
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

#ifndef PANT_POSITION_CONTROLLER__PANT_POSITION_CONTROLLER_HPP_
#define PANT_POSITION_CONTROLLER__PANT_POSITION_CONTROLLER_HPP_
#include <memory>
#include <string>
#include <vector>

#include <algorithm>
#include <cmath>
#include <complex>

#include "controller_interface/controller_interface.hpp"
#include "pant_position_controller/visibility_control.h"
#include "rclcpp/subscription.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_buffer.h"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

namespace pant_position_controller
{
using CmdType = std_msgs::msg::Float64MultiArray;
using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class PantPositionController : public controller_interface::ControllerInterface
{
public:
  PANT_POSITION_CONTROLLER_PUBLIC
  PantPositionController();

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_init() override;

  PANT_POSITION_CONTROLLER_PUBLIC
  controller_interface::InterfaceConfiguration command_interface_configuration() const override;

  PANT_POSITION_CONTROLLER_PUBLIC
  controller_interface::InterfaceConfiguration state_interface_configuration() const override;

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state) override;

  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_error(const rclcpp_lifecycle::State &previous_state) override;
  
  PANT_POSITION_CONTROLLER_PUBLIC
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State &previous_state) override;

  PANT_POSITION_CONTROLLER_PUBLIC
  controller_interface::return_type update(
    const rclcpp::Time & time,
    const rclcpp::Duration & period) override;

protected:
  std::vector<std::string> joint_names_;
  double effort_limits_;

  realtime_tools::RealtimeBuffer<std::shared_ptr<CmdType>> rt_command_ptr_, rt_enable_ptr_, rt_desired_angles_ptr_;
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr joints_command_subscriber_, drivers_enable_subscriber_, desired_angles_subscriber_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr actual_angles_publisher_;
  rclcpp::Duration elapsed_time_ = rclcpp::Duration(0,0);

  std::string logger_name_;
  double joint1, joint2;
  double a1=100, a2=165, a3=165, a4=100, a5=85, RED_RATIO=10, OFFSET_JOINT1 = 147.0 * M_PI/180, OFFSET_JOINT2 = 33 * M_PI/180;
  double H = 90, phi, theta;
  std::complex<double> P1, P2, P3, P4, P5, C, P3_des;
  double l24, gamma24, th2, th4, gamma;
  double q1=0.0, q2=0.0, q1_prev, q2_prev, v1, v2;

};

}  // namespace 

#endif  // 