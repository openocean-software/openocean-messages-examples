#include <chrono>

#include <openocean_msgs_convert/convert.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("navigation_publisher");
    auto publisher = node->create_publisher<openocean_msgs::msg::Navigation>("navigation", 10);

    auto publish = [&]()
    {
        openocean::Navigation nav;
        nav.set_time(node->now().nanoseconds() / 1000);
        nav.mutable_vehicle()->set_name("auv1");
        nav.mutable_geodetic()->set_latitude(41.52);
        nav.mutable_geodetic()->set_depth(10);

        openocean_msgs::msg::Navigation msg;
        openocean::to_ros(nav, &msg);
        publisher->publish(msg);
    };
    auto timer = node->create_wall_timer(1s, publish);

    rclcpp::spin(node);
    rclcpp::shutdown();
}
