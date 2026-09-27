import time

from openocean.messages import common_pb2, navigation_pb2

nav = navigation_pb2.Navigation()
nav.time = time.time_ns() // 1000
nav.vehicle.name = "auv1"
nav.geodetic.latitude = 41.52
nav.geodetic.longitude = -70.67
nav.geodetic.depth = 10
nav.attitude.heading = 1.57  # radians
nav.speed.add(value=1.5, mode=common_pb2.SPEED_MODE_OVER_GROUND)

received = navigation_pb2.Navigation.FromString(nav.SerializeToString())
print(received)
