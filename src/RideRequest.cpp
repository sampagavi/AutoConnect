#include "RideRequest.h"

RideRequest::RideRequest(std::string name, Location loc, int urg)
    : studentName(name), location(loc), urgency(urg) {}

bool RideRequest::operator<(const RideRequest& other) const {
    return urgency < other.urgency; // Higher urgency = higher priority
}

