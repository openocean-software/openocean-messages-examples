cmake_minimum_required(VERSION 3.10)
project(openocean_example_ros CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(openocean_msgs REQUIRED)
find_package(openocean_msgs_convert REQUIRED)

add_executable(navigation_publisher navigation_publisher.cpp)
target_link_libraries(navigation_publisher
  rclcpp::rclcpp
  ${openocean_msgs_TARGETS}
  openocean_msgs_convert::openocean_msgs_convert)

install(TARGETS navigation_publisher DESTINATION lib/${PROJECT_NAME})

ament_package()
