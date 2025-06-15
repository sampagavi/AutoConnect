#ifndef USER_H
#define USER_H

#include <string>

struct Location {
    double latitude;
    double longitude;

    Location(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}

    double distanceTo(const Location& other) const;
};

class Driver {
public:
    std::string name;
    Location location;
    bool isAvailable;

    Driver(std::string n, Location loc);
};

#endif
