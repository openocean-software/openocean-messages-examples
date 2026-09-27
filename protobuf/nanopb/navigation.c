#include <stdio.h>

#include <pb_decode.h>
#include <pb_encode.h>

#include "openocean/messages/navigation.pb.h"

int main(void)
{
    openocean_Navigation nav = openocean_Navigation_init_zero;
    nav.has_geodetic = true;
    nav.geodetic.has_latitude = true;
    nav.geodetic.latitude = 41.52;
    nav.geodetic.has_depth = true;
    nav.geodetic.depth = 10;
    nav.speed_count = 1;
    nav.speed[0].has_value = true;
    nav.speed[0].value = 1.5;

    uint8_t buffer[openocean_Navigation_size];
    pb_ostream_t out = pb_ostream_from_buffer(buffer, sizeof(buffer));
    if (!pb_encode(&out, openocean_Navigation_fields, &nav))
        return 1;

    openocean_Navigation received = openocean_Navigation_init_zero;
    pb_istream_t in = pb_istream_from_buffer(buffer, out.bytes_written);
    if (!pb_decode(&in, openocean_Navigation_fields, &received))
        return 1;
    printf("%zu bytes: latitude %f, depth %f, speed %f\n", out.bytes_written,
           received.geodetic.latitude, received.geodetic.depth, received.speed[0].value);
    return 0;
}
