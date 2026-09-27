#include <chrono>
#include <iostream>

#include "openocean/messages/navigation.pb.h"

int main()
{
    openocean::Navigation nav;
    nav.set_time(std::chrono::duration_cast<std::chrono::microseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count());
    nav.mutable_vehicle()->set_name("auv1");
    nav.mutable_geodetic()->set_latitude(41.52);
    nav.mutable_geodetic()->set_longitude(-70.67);
    nav.mutable_geodetic()->set_depth(10);
    nav.mutable_attitude()->set_heading(1.57); // radians
    auto* speed = nav.add_speed();
    speed->set_value(1.5);
    speed->set_mode(openocean::SPEED_MODE_OVER_GROUND);

    std::string bytes = nav.SerializeAsString();

    openocean::Navigation received;
    if (!received.ParseFromString(bytes))
        return 1;
    std::cout << received.DebugString();
}
