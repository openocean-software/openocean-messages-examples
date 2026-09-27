cmake_minimum_required(VERSION 3.13...4.2.3)
project(openocean_example_lcm CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS cpp lcm)
# lcm's own CMake package doesn't load with CMake 4
find_package(PkgConfig REQUIRED)
pkg_check_modules(LCM REQUIRED IMPORTED_TARGET lcm)

add_executable(navigation_publisher navigation_publisher.cpp)
target_link_libraries(navigation_publisher PRIVATE openocean_messages::lcm_convert PkgConfig::LCM)

enable_testing()
add_test(NAME navigation_publisher COMMAND navigation_publisher)
# In-process, so the test doesn't need a multicast route
set_tests_properties(navigation_publisher PROPERTIES ENVIRONMENT LCM_DEFAULT_URL=memq://)
