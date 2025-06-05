/*#include <iostream>
#include "AutoConnect.h"

int main() {
    std::cout << "Welcome to AutoConnect!" << std::endl;
    // Your main program code
    return 0;
}*/


#include <iostream>
#include <vector>
#include <algorithm>
#include "RideRequest.h"

void createRequest(std::vector<RideRequest>& requests, int& requestCounter) {
    int studentId;
    std::string pickup, dest;
    int urgencyInput;

    std::cout << "\n--- Create Ride Request ---\n";
    std::cout << "Enter Student ID: ";
    std::cin >> studentId;

    std::cin.ignore(); // clear buffer
    std::cout << "Enter Pickup Location: ";
    std::getline(std::cin, pickup);

    std::cout << "Enter Destination: ";
    std::getline(std::cin, dest);

    std::cout << "Urgency (0 = LOW, 1 = MEDIUM, 2 = HIGH): ";
    std::cin >> urgencyInput;

    RideRequest req(requestCounter++, studentId, pickup, dest, static_cast<UrgencyLevel>(urgencyInput));
    requests.push_back(req);
    std::cout << "Ride request created successfully!\n";
}

void viewRequests(const std::vector<RideRequest>& requests) {
    std::cout << "\n--- Ride Requests ---\n";

    std::vector<RideRequest> sorted = requests;
    std::sort(sorted.begin(), sorted.end(), [](const RideRequest& a, const RideRequest& b) {
        return a.urgency > b.urgency;
    });

    for (const auto& req : sorted) {
        std::cout << "Request ID: " << req.requestId << " | Student ID: " << req.studentId
                  << " | From: " << req.pickupLocation << " | To: " << req.destination
                  << " | Urgency: " << req.urgency << " | Handled: "
                  << (req.isHandled ? "Yes" : "No") << "\n";
    }
}

void handleRequest(std::vector<RideRequest>& requests) {
    int reqId;
    std::cout << "\n--- Handle Ride Request ---\n";
    std::cout << "Enter Request ID to mark as handled: ";
    std::cin >> reqId;

    for (auto& req : requests) {
        if (req.requestId == reqId) {
            req.isHandled = true;
            std::cout << "Request marked as handled.\n";
            return;
        }
    }
    std::cout << "Request ID not found.\n";
}

void inputFeedback(std::vector<RideRequest>& requests) {
    int reqId;
    std::string feedback;
    std::cin.ignore(); // clear buffer
    std::cout << "\n--- Input Feedback ---\n";
    std::cout << "Enter Request ID: ";
    std::cin >> reqId;
    std::cin.ignore();

    for (auto& req : requests) {
        if (req.requestId == reqId && req.isHandled) {
            std::cout << "Enter feedback: ";
            std::getline(std::cin, feedback);
            req.feedback = feedback;
            std::cout << "Feedback saved.\n";
            return;
        }
    }

    std::cout << "Request ID not found or not handled yet.\n";
}

int main() {
    std::vector<RideRequest> requests;
    int requestCounter = 1;
    int choice;

    while (true) {
        std::cout << "\n==== AutoConnect Menu ====\n";
        std::cout << "1. Create Ride Request\n";
        std::cout << "2. View Requests\n";
        std::cout << "3. Handle Request\n";
        std::cout << "4. Input Feedback\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: createRequest(requests, requestCounter); break;
            case 2: viewRequests(requests); break;
            case 3: handleRequest(requests); break;
            case 4: inputFeedback(requests); break;
            case 5: std::cout << "Exiting...\n"; return 0;
            default: std::cout << "Invalid choice.\n";
        }
    }
}
