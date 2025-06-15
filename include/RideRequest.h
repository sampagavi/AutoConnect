#ifndef RIDEREQUEST_H
#define RIDEREQUEST_H

#include <string>
#include "User.h"

struct RideRequest {
    std::string studentName;
    Location location;
    int urgency;

    RideRequest(std::string name, Location loc, int urg)
        : studentName(name), location(loc), urgency(urg) {}

    // Higher urgency gets higher priority. If urgency is same, shorter distance is preferred.
    bool operator<(const RideRequest& other) const {
        return urgency < other.urgency;
    }
};

#endif


