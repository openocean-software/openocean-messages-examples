cmake_minimum_required(VERSION 3.13...4.2.3)
project(openocean_example_nanopb C)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS nanopb)

add_executable(navigation navigation.c)
target_link_libraries(navigation PRIVATE openocean_messages::nanopb)

enable_testing()
add_test(NAME navigation COMMAND navigation)
