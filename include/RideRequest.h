#ifndef RIDEREQUEST_H
#define RIDEREQUEST_H

#include <string>
#include "User.h"

struct RideRequest {
    std::string studentName;
    Location location;
    int urgency;

    RideRequest(std::string name, Location loc, int urg);
    bool operator<(const RideRequest& other) const;
};

#endif

