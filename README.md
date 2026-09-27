# openocean-messages-examples
Examples for how to use openocean-messages in downstream projects.

## Examples

*This section was written by Claude.*

Each directory is an independent CMake project that uses [openocean-messages](https://github.com/openocean-software/openocean-messages) through `find_package(openocean_messages)`:

| Example | Shows | openocean-messages output (`init.sh`) |
|---|---|---|
| [protobuf/cxx](protobuf/cxx) | Protobuf C++: build, serialize, and parse a `Navigation` | `--cxx` |
| [protobuf/composition](protobuf/composition) | Extending `Navigation` by wrapping it in a project's own message | `--cxx` |
| [protobuf/python](protobuf/python) | Protobuf Python | `--python` |
| [protobuf/nanopb](protobuf/nanopb) | nanopb (C) | `--nanopb` |
| [lcm](lcm) | Converting Protobuf to LCM and publishing it | `--cxx --lcm` |
| [ros](ros) | A ROS 2 node publishing `openocean_msgs/Navigation`, converted from Protobuf | `--ros` |

## Building

*This section was written by Claude.*

Build openocean-messages with the outputs the example needs, then point the example at it, either installed (`cmake --install`, found on the default prefix or `CMAKE_PREFIX_PATH`) or in its build directory:

```
cmake -S protobuf/cxx -B build/cxx -Dopenocean_messages_DIR=/path/to/openocean-messages/build
cmake --build build/cxx
ctest --test-dir build/cxx
```

The ROS 2 example is a colcon package that uses the ROS 2 packages openocean-messages generates, and also needs `rclcpp`:

```
colcon build --base-paths /path/to/openocean-messages/build/ros ros
```

The LCM example's test publishes in-process (`LCM_DEFAULT_URL=memq://`); run it directly to publish on the network.
