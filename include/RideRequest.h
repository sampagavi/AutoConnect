/*#ifndef RIDEREQUEST_H
#define RIDEREQUEST_H

#include <string>

enum UrgencyLevel { LOW, MEDIUM, HIGH };

class RideRequest {
public:
    int requestId;
    int studentId;
    std::string pickupLocation;
    std::string destination;
    UrgencyLevel urgency;
    bool isHandled;
    std::string feedback;

    RideRequest(int _requestId, int _studentId, std::string _pickup,
                std::string _dest, UrgencyLevel _urgency);
};

#endif*/

#ifndef RIDEREQUEST_H
#define RIDEREQUEST_H

#include <string>

enum UrgencyLevel { LOW, MEDIUM, HIGH };

class RideRequest {
public:
    int requestId;
    int studentId;
    std::string pickupLocation;
    std::string destination;
    UrgencyLevel urgency;
    bool isHandled;
    std::string feedback;

    RideRequest(int _requestId, int _studentId, const std::string& _pickup,
                const std::string& _dest, UrgencyLevel _urgency);
};

#endif 

