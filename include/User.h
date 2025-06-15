#ifndef USER_H
#define USER_H

#include <string>
#include "GeoUtils.h"  // So Driver can use Location

class Driver {
public:
    std::string name;
    Location location;
    bool isAvailable;

    Driver(std::string n, Location loc);
};

#endif

