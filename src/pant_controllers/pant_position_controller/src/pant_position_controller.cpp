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

#include "pant_position_controller/pant_position_controller.hpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

#include "rclcpp/logging.hpp"
#include "rclcpp/qos.hpp"

#include "hardware_interface/loaned_command_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

namespace pant_position_controller
{
using hardware_interface::LoanedCommandInterface;

PantPositionController::PantPositionController():controller_interface::ControllerInterface(),
  rt_command_ptr_(nullptr),
  rt_enable_ptr_(nullptr),
  joints_command_subscriber_(nullptr), 
  drivers_enable_subscriber_(nullptr)
{
}
CallbackReturn PantPositionController::on_init()
{
  try {
    // definition of the parameters that need to be queried from the
    // controller configuration file with default values
    auto_declare<std::vector<std::string>>("joints", std::vector<std::string>());
    auto_declare<double>("effort_limit", double());

  } catch (const std::exception & e) {
    fprintf(stderr, "Exception thrown during init stage with message: %s \n", e.what());
    return CallbackReturn::ERROR;
  }

  return CallbackReturn::SUCCESS;
}

CallbackReturn PantPositionController::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  elapsed_time_ = rclcpp::Duration(0,0);
  // getting the names of the joints to be controlled
  joint_names_ = get_node()->get_parameter("joints").as_string_array();
  effort_limits_ = get_node()->get_parameter("effort_limits").as_double();

  if (joint_names_.empty()) {
    RCLCPP_ERROR(get_node()->get_logger(), "'joints' parameter was empty");
    return CallbackReturn::FAILURE;
  }
 
  // the desired cartesian velocity is queried from the joint_velocity topic
  // and passed to update via a rt pipe
  joints_command_subscriber_ = get_node()->create_subscription<CmdType>(
    "~/joint_effort", rclcpp::SystemDefaultsQoS(),
    [this](const CmdType::SharedPtr msg) {rt_command_ptr_.writeFromNonRT(msg);});
    
  drivers_enable_subscriber_ = get_node()->create_subscription<CmdType>(
    "~/enable", rclcpp::SystemDefaultsQoS(),
    [this](const CmdType::SharedPtr msg) {rt_enable_ptr_.writeFromNonRT(msg);});

  actual_angles_publisher_ = get_node()->create_publisher<std_msgs::msg::Float64MultiArray>(
  "actual_angles", rclcpp::SystemDefaultsQoS());

  desired_angles_subscriber_ = get_node()->create_subscription<CmdType>(
    "desired_angles", rclcpp::SystemDefaultsQoS(),
    [this](const CmdType::SharedPtr msg) {rt_desired_angles_ptr_.writeFromNonRT(msg);});

  RCLCPP_INFO(get_node()->get_logger(), "configure successful");
  return CallbackReturn::SUCCESS;
}
// As the demo scara hardware interface only supports position commands, it can be directly
// defined here without the need of getting as parameter. The position interface is then 
// affected to all controlled joints.
controller_interface::InterfaceConfiguration
PantPositionController::command_interface_configuration() const
{
  controller_interface::InterfaceConfiguration conf;
  conf.type = controller_interface::interface_configuration_type::INDIVIDUAL;
  conf.names.reserve(joint_names_.size() + 4);
  for (const auto & joint_name : joint_names_) {
    conf.names.push_back(joint_name + "/" + hardware_interface::HW_IF_POSITION);
  }
  conf.names.push_back(std::string("joint1/") + hardware_interface::HW_IF_EFFORT+".1"); // Torque command interface for joint 1
  conf.names.push_back(std::string("joint2/") + hardware_interface::HW_IF_EFFORT+".2"); // Torque command interface for joint 2
  conf.names.push_back(std::string("joint1/enable"));
  conf.names.push_back(std::string("joint2/enable"));
  
  // Display the content of the 'conf' variable using the logger
  std::stringstream ss;
  for (const auto& name : conf.names) {
    ss << name << ", ";
  }
  RCLCPP_INFO(get_node()->get_logger(), "InterfaceConfiguration: [%s]", ss.str().c_str());

  return conf;
}
// The controller requires the current position states. For this reason
// it can be directly defined here without the need of getting as parameters.
// The state interface is then deployed to all targeted joints.
controller_interface::InterfaceConfiguration
PantPositionController::state_interface_configuration() const
{
  controller_interface::InterfaceConfiguration conf;
  conf.type = controller_interface::interface_configuration_type::INDIVIDUAL;
  conf.names.reserve(joint_names_.size());
  for (const auto & joint_name : joint_names_) {
    conf.names.push_back(joint_name + "/" + hardware_interface::HW_IF_POSITION);
  }
  return conf;
}

// Fill ordered_interfaces with references to the matching interfaces
// in the same order as in joint_names
// template<typename T>
// bool get_ordered_interfaces(
//   std::vector<T> & unordered_interfaces, const std::vector<std::string> & joint_names,
//   const std::string & interface_type, std::vector<std::reference_wrapper<T>> & ordered_interfaces)
// {
//   for (const auto & joint_name : joint_names) {
//     for (auto & command_interface : unordered_interfaces) {
//       if (command_interface.get_name() == joint_name + "/" + interface_type) {
//         ordered_interfaces.push_back(std::ref(command_interface));
//       }
//     }
//   }

//   return joint_names.size() == ordered_interfaces.size();
// }

CallbackReturn PantPositionController::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // std::vector<std::reference_wrapper<LoanedCommandInterface>> ordered_interfaces;
  // if (!get_ordered_interfaces(command_interfaces_, joint_names_, hardware_interface::HW_IF_POSITION, ordered_interfaces) ||
  //   command_interfaces_.size() != ordered_interfaces.size())
  // {
  //   RCLCPP_ERROR(
  //     get_node()->get_logger(), "Expected %zu position command interfaces, got %zu",
  //     joint_names_.size(),
  //     ordered_interfaces.size());
  //   return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::ERROR;
  // }

  command_interfaces_[6].set_value(0.0);
  command_interfaces_[7].set_value(0.0);

   RCLCPP_INFO(
    get_node()->get_logger(), "Command Interfaces:");
  for (size_t i = 0; i < command_interfaces_.size(); ++i) {
    RCLCPP_INFO(
      get_node()->get_logger(), "Interface: %p", command_interfaces_[i].get_name());
  }


  return CallbackReturn::SUCCESS;
}

CallbackReturn PantPositionController::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn PantPositionController::on_cleanup(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn PantPositionController::on_error(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn PantPositionController::on_shutdown(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  return CallbackReturn::SUCCESS;
}

// main control loop function getting the state interface and writing to the command interface
controller_interface::return_type PantPositionController::update(
  const rclcpp::Time & /*time*/,
  const rclcpp::Duration & period)
{
  elapsed_time_ = elapsed_time_ + period;
  auto enable = rt_enable_ptr_.readFromRT();
  bool ENABLE_FLAG = false; 

  // enabling the drivers
  if (*(enable) && enable){
    ENABLE_FLAG = (*enable)->data[0] == 1;
  } 
  
  if (ENABLE_FLAG){
    command_interfaces_[6].set_value(5.0);
    command_interfaces_[7].set_value(5.0);
  }
  else {
    command_interfaces_[6].set_value(0.0);
    command_interfaces_[7].set_value(0.0);
    
    command_interfaces_[4].set_value(0.0); // stop the motors when disabled so that next time 
    command_interfaces_[5].set_value(0.0); // you enable they do not start spinning randomly
  }

  // getting the data from the subscriber using the rt pipe
  // auto controlled_joints = rt_command_ptr_.readFromRT();
  auto desired_angles = rt_desired_angles_ptr_.readFromRT();

  double q1_prev = q1;
  double q2_prev = q2;

  q1 = state_interfaces_[0].get_value() + OFFSET_JOINT1; ///RED_RATIO; 
  q2 = state_interfaces_[1].get_value() + OFFSET_JOINT2; ///RED_RATIO;


  // ------------- FKM --------------
  P1 = std::complex<double>(0, 0);
  P5 = std::complex<double>(a5, 0);
  C = std::complex<double>(42.5, 160.56);

  P2 = P1 + std::polar(a1, q1);
  P4 = P5 + std::polar(a4, q2);

  l24 = std::abs(P4-P2);


  gamma24 = std::arg(P4-P2);
  gamma = std::acos( (pow(l24, 2) + pow(a2, 2) - pow(a3, 2)) / (2*a2*l24) );
  th2 = gamma24 + gamma;

  P3 = P2 + std::polar(a2,th2);
  // RCLCPP_INFO(get_node()->get_logger(), "P3: %f, %f", P3.real(), P3.imag());
  th4 = std::atan2( (P3-P4).imag(), (P3-P4).real());

  // for rviz
  double q3 = -(q1-th2);
  double q4 = th4-q2;

  double r = std::norm(P3-C);
  phi = std::atan(r / H) *180/M_PI;
  theta = std::atan2( (P3-C).imag()/r, (P3-C).real()/r) *180/M_PI;


  auto angles_message = std_msgs::msg::Float64MultiArray();
  angles_message.data.push_back(phi);
  angles_message.data.push_back(theta);
  actual_angles_publisher_->publish(angles_message);
  // ------------- FKM --------------


  // ------------ DESIRED FKM --------------
  // ----------- DESIRED FKM ----------------

  if ((*desired_angles) && desired_angles){

  // ----------- DESIRED IKM ----------------
    double phi_des = (*desired_angles)->data[0];
    double th_des = (*desired_angles)->data[1];
      // RCLCPP_INFO(get_node()->get_logger(), "desired phi: %f, desired theta: %f", phi_des, th_des);

    double P3_real = - H * std::tan(phi_des) * std::cos(th_des);
    double P3_im = - H * std::tan(phi_des) * std::sin(th_des);

    P3_des = std::complex<double>(P3_real, P3_im);
    P3_des += C;
    // RCLCPP_INFO(get_node()->get_logger(), "P3 des: %f, %f", P3_des.real(), P3_des.imag());

    double alpha1 = std::acos( (pow(a1,2) + pow(std::abs(P3_des),2) - pow(a2,2)) / (2*a1*std::abs(P3_des)) );
    double beta1 = std::atan2(P3_des.imag(), P3_des.real());
      // RCLCPP_INFO(get_node()->get_logger(), "alpha1: %f,  alpha2: %f", alpha1, beta1);

    double alpha2 = std::acos( (pow(a4,2) + pow(std::abs(P3_des - P5),2) - pow(a3,2)) / (2*a1*std::abs(P3_des - P5)) );
    double beta2 = std::atan2(P3_des.imag(), (P5-P3_des).real());
      // RCLCPP_INFO(get_node()->get_logger(), "alpha2: %f, beta2: %f", alpha2, beta2);


    double q1_des = alpha1 + beta1;
    double q2_des = M_PI - alpha2 - beta2; 
// ------------- DESIRED IKM -------------------

  // ----------- CONTROL ALGORITHM 
    if (ENABLE_FLAG && elapsed_time_.nanoseconds()*1e-9 >= 2.0) {
      elapsed_time_ = rclcpp::Duration(0,0);
      double v1 = 0.9*(q1_des - q1);
      double v2 = 0.9*(q2_des - q2);
      RCLCPP_INFO(get_node()->get_logger(), "Error: %f, %f", q1_des - q1, q2_des-q1);
      RCLCPP_INFO(get_node()->get_logger(), "Command: %f, %f", v1, v2);


      command_interfaces_[4].set_value(v1);
      command_interfaces_[5].set_value(v2);
    }
    // ----------- CONTROL ALGORITHM
}

  // JUST FOR RVIZ
  command_interfaces_[0].set_value(q1);
  command_interfaces_[1].set_value(q2);
  command_interfaces_[2].set_value(q3);
  command_interfaces_[3].set_value(q4);

  return controller_interface::return_type::OK;
}

}  // namespace scara_joint_velocity_controller

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  pant_position_controller::PantPositionController, controller_interface::ControllerInterface)