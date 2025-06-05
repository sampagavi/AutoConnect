/*#include "RideRequest.h"

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
}*/

#include "RideRequest.h"

RideRequest::RideRequest(int _requestId, int _studentId, const std::string& _pickup,
                         const std::string& _dest, UrgencyLevel _urgency)
    : requestId(_requestId), studentId(_studentId), pickupLocation(_pickup),
      destination(_dest), urgency(_urgency), isHandled(false), feedback("") {}
