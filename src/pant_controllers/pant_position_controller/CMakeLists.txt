cmake_minimum_required(VERSION 3.5)
project(pant_position_controller)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-deprecated-copy)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(controller_interface REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(realtime_tools REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_library(pant_position_controller
  SHARED
  src/pant_position_controller.cpp
)
target_include_directories(pant_position_controller PRIVATE include)
ament_target_dependencies(pant_position_controller
  builtin_interfaces
  controller_interface
  hardware_interface
  pluginlib
  rclcpp_lifecycle
  rcutils
  realtime_tools
  std_msgs
)
# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(pant_position_controller PRIVATE "pant_position_controller_BUILDING_DLL")
# prevent pluginlib from using boost
target_compile_definitions(pant_position_controller PUBLIC "PLUGINLIB__DISABLE_BOOST_FUNCTIONS")
pluginlib_export_plugin_description_file(controller_interface controller_plugin.xml)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS
  pant_position_controller
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

ament_export_dependencies(
  controller_interface
  hardware_interface
  rclcpp
  rclcpp_lifecycle
  realtime_tools
  std_msgs
)
ament_export_include_directories(
  include
)
ament_export_libraries(
  pant_position_controller
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()