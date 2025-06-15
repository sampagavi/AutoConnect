#include "User.h"
#include <cmath>

double Location::distanceTo(const Location& other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

Driver::Driver(std::string n, Location loc) {
    name = n;
    location = loc;
    isAvailable = true;
}
