cmake_minimum_required(VERSION 3.13...4.2.3)
project(openocean_example_python NONE)

find_package(openocean_messages 0.1 REQUIRED COMPONENTS python)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

enable_testing()
add_test(NAME navigation COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/navigation.py)
# Unnecessary once installed to Python's own path, but not for a build directory or other prefix
set_tests_properties(navigation PROPERTIES ENVIRONMENT PYTHONPATH=${openocean_messages_PYTHON_DIR})
