cmake_minimum_required(VERSION 3.13...4.2.3)
project(openocean_example_composition CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS cpp)

# Generates only this project's protos: openocean's come from its library
add_library(example_messages)
protobuf_generate(
  TARGET example_messages
  LANGUAGE cpp
  PROTOS example/contact_report.proto
  IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${openocean_messages_PROTO_DIR}
  PROTOC_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(example_messages PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(example_messages PUBLIC openocean_messages::openocean_messages)

add_executable(contact_report contact_report.cpp)
target_link_libraries(contact_report PRIVATE example_messages)

enable_testing()
add_test(NAME contact_report COMMAND contact_report)
