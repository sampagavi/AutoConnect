#include "RideRequest.h"

RideRequest::RideRequest(int requestId, const std::string& pickupLocation, const std::string& dropoffLocation)
    : requestId(requestId), pickupLocation(pickupLocation), dropoffLocation(dropoffLocation) {}

int RideRequest::getRequestId() const {
    return requestId;
}

std::string RideRequest::getPickupLocation() const {
    return pickupLocation;
}

std::string RideRequest::getDropoffLocation() const {
    return dropoffLocation;
}
