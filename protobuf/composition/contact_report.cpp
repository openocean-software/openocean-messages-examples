#include <iostream>

#include "example/contact_report.pb.h"

int main()
{
    example::ContactReport report;
    report.mutable_nav()->mutable_vehicle()->set_name("ferry");
    report.mutable_nav()->mutable_enu()->set_e(120);
    report.mutable_nav()->mutable_enu()->set_n(-45);
    report.set_type("ship");
    report.set_length(60);

    example::ContactReport received;
    if (!received.ParseFromString(report.SerializeAsString()))
        return 1;
    std::cout << received.DebugString();
}
