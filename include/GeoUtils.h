#ifndef GEO_UTILS_H
#define GEO_UTILS_H

#include <string>

struct Location {
    double latitude;
    double longitude;

    Location(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}
};

Location getCoordinatesFromLocationName(const std::string& placeName);

#endif
