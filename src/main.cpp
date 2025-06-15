#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <iomanip>  // for std::setprecision
#include "RideRequest.h"
#include "User.h"
#include "AutoConnect.h"
#include "GeoUtils.h"

using namespace std;

priority_queue<RideRequest> requestQueue;
vector<Driver> drivers;

Location inputLocationByName(const string& prompt) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string place;
    cout << prompt;
    getline(cin, place);
    Location loc = getCoordinatesFromLocationName(place);
    cout << fixed << setprecision(6); 
    cout << "Coordinates fetched: (" << loc.latitude << ", " << loc.longitude << ")\n";
    return loc;
}

void studentRequestRide() {
    string name;
    int urgency;
    cout << "\n--- Student Ride Request ---\n";
    cout << "Enter your name: ";
    cin >> name;

    Location loc = inputLocationByName("Enter your pickup location name: ");

    cout << "Enter urgency (1 to 5): ";
    cin >> urgency;

    requestQueue.push(RideRequest(name, loc, urgency));
    cout << "Ride request submitted!\n";
}

void driverAcceptRide() {
    string name;
    cout << "\n--- Driver Login ---\n";
    cout << "Enter your name: ";
    cin >> name;

    Location loc = inputLocationByName("Enter your current location name: ");

    Driver driver(name, loc);
    drivers.push_back(driver);
    int driverIndex = drivers.size() - 1;

    if (requestQueue.empty()) {
        cout << "No requests available.\n";
        return;
    }

    vector<RideRequest> temp;
    RideRequest bestRequest("", Location(), -1);
    double bestDistance = numeric_limits<double>::max();
    bool found = false;

    while (!requestQueue.empty()) {
        RideRequest r = requestQueue.top();
        requestQueue.pop();
        temp.push_back(r);

        double d = driver.location.distanceTo(r.location);
        if (!found || r.urgency > bestRequest.urgency ||
            (r.urgency == bestRequest.urgency && d < bestDistance)) {
            bestRequest = r;
            bestDistance = d;
            found = true;
        }
    }

    for (RideRequest r : temp) {
        if (!(r.studentName == bestRequest.studentName &&
              r.urgency == bestRequest.urgency &&
              r.location.latitude == bestRequest.location.latitude &&
              r.location.longitude == bestRequest.location.longitude)) {
            requestQueue.push(r);
        }
    }

    cout << "\nNearest urgent request:\n";
    cout << "Student: " << bestRequest.studentName
         << "\nUrgency: " << bestRequest.urgency
         << "\nDistance: " << bestDistance << " units\n";

    cout << "Accept this ride? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        drivers[driverIndex].isAvailable = false;
        cout << "Ride accepted.\n";
    } else {
        cout << "Ride not accepted.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n==== AutoConnect Menu ====\n";
        cout << "1. Student - Request Ride\n";
        cout << "2. Driver - Accept Ride\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: studentRequestRide(); break;
            case 2: driverAcceptRide(); break;
            case 3: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid input. Try again.\n";
        }
    }
}
