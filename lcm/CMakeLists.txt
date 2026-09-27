cmake_minimum_required(VERSION 3.18...4.2.3)
project(openocean_example_lcm CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS cpp lcm)
# lcm's CMake package doesn't load with CMake 4, and its pkg-config file requires glib's, which
# liblcm-dev doesn't install
find_library(LCM_LIBRARY lcm REQUIRED)
find_path(LCM_INCLUDE_DIR lcm/lcm-cpp.hpp REQUIRED)

add_executable(navigation_publisher navigation_publisher.cpp)
target_include_directories(navigation_publisher PRIVATE ${LCM_INCLUDE_DIR})
target_link_libraries(navigation_publisher PRIVATE openocean_messages::lcm_convert ${LCM_LIBRARY})

enable_testing()
add_test(NAME navigation_publisher COMMAND navigation_publisher)
# In-process, so the test doesn't need a multicast route
set_tests_properties(navigation_publisher PROPERTIES ENVIRONMENT LCM_DEFAULT_URL=memq://)
