#include "User.h"
#include <cmath>

double Location::distanceTo(const Location& other) const {
    return sqrt((latitude - other.latitude) * (latitude - other.latitude) +
                (longitude - other.longitude) * (longitude - other.longitude));
}

Driver::Driver(std::string n, Location loc) {
    name = n;
    location = loc;
    isAvailable = true;
}
