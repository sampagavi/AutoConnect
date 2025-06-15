#ifndef USER_H
#define USER_H

#include <string>
#include <cmath>

struct Location {
    double x, y;  // Changed from int to double
    Location(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double distanceTo(const Location& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

class Driver {
public:
    std::string name;
    Location location;
    bool isAvailable;

    Driver(std::string n, Location loc);
};

#endif
