#ifndef USER_H
#define USER_H

#include <string>

struct Location {
    int x, y;
    Location(int x = 0, int y = 0) : x(x), y(y) {}

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
