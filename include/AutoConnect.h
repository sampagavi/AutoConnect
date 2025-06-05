#ifndef AUTOCONNECT_H
#define AUTOCONNECT_H

#include "User.h"
#include "RideRequest.h"

class AutoConnect {
public:
    void addUser(const User& user);
    void addRideRequest(const RideRequest& request);
    // Other main functions declarations
};

#endif // AUTOCONNECT_H
