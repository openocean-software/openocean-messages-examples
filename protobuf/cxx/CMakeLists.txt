cmake_minimum_required(VERSION 3.13...4.2.3)
project(openocean_example_cxx CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS cpp)

add_executable(navigation navigation.cpp)
target_link_libraries(navigation PRIVATE openocean_messages::openocean_messages)

enable_testing()
add_test(NAME navigation COMMAND navigation)
