#include "GeoUtils.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <iostream>

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    out->append((char*)contents, size * nmemb);
    return size * nmemb;
}

Location getCoordinatesFromLocationName(const std::string& placeName) {
    CURL* curl = curl_easy_init();
    std::string buffer;

    if (!curl) {
        std::cerr << "Error: CURL init failed.\n";
        return Location(0,0);
    }

    std::ostringstream url;
    url << "https://nominatim.openstreetmap.org/search?q="
        << curl_easy_escape(curl, placeName.c_str(), 0)
        << "&format=json&limit=1";

    curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "AutoConnect/1.0");

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cerr << "Error: Network request failed.\n";
        return Location(0,0);
    }

    try {
        auto arr = json::parse(buffer);
        if (!arr.is_array() || arr.empty()) {
            std::cerr << "Location not found.\n";
            return Location(0,0);
        }
        double lat = std::stod(arr[0]["lat"].get<std::string>());
        double lon = std::stod(arr[0]["lon"].get<std::string>());
        return Location(static_cast<int>(lat), static_cast<int>(lon));
    } catch (...) {
        std::cerr << "Error: JSON parse failed.\n";
        return Location(0,0);
    }
}
