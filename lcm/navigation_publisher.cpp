#include <iostream>

#include <lcm/lcm-cpp.hpp>

#include "openocean/lcm_convert.h"

int main()
{
    openocean::Navigation nav;
    nav.mutable_vehicle()->set_name("auv1");
    nav.mutable_geodetic()->set_latitude(41.52);
    nav.mutable_geodetic()->set_depth(10);

    openocean::navigation_t msg;
    openocean::to_lcm(nav, &msg);

    lcm::LCM lcm;
    if (!lcm.good() || lcm.publish("NAVIGATION", &msg) != 0)
        return 1;
    std::cout << "Published NAVIGATION for " << msg.vehicle.name << "\n";
}
