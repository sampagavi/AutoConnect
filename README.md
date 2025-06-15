#  AutoConnect - Urgent Ride Request System

**AutoConnect** is a terminal-based ride request and assignment system built in **C++**, designed to help **students in emergencies** quickly request rides from available **auto drivers** on campus. It features **urgency-based prioritization**, **distance-based matching**, and **live location fetching using OpenStreetMap API**.

---

##  Why AutoConnect?

Students often struggle to find autos during urgent situations (medical emergencies, time-sensitive classes, etc.). AutoConnect enables:

- Students to **search locations by name** (e.g., "Main Gate", "Library")
- Auto drivers to **view and accept nearest requests**
- A **priority queue** that selects rides based on **urgency** and **proximity**

---

##  Features

-  **Search Location by Name** using OpenStreetMap Nominatim API
-  **Urgency-Based Priority Queue** (1 to 5)
-  **Shortest Distance Matching** for drivers
-  Students request rides from terminal
-  Auto drivers can accept rides from queue
-  Clean, modular structure using C++ headers and classes

---

##  Project Structure

AutoConnect/
├── include/
│ ├── RideRequest.h # Ride request class
│ ├── User.h # User and Location classes
│ ├── AutoConnect.h # Function declarations
│ └── GeoUtils.h # API utility to fetch coordinates
├── src/
│ ├── main.cpp # Main terminal logic
│ ├── RideRequest.cpp
│ ├── User.cpp
│ └── GeoUtils.cpp # Uses libcurl + nlohmann/json
├── include/json.hpp # nlohmann JSON library (header-only)
└── README.md

##  How to Run

###  Requirements
- C++17 compiler (e.g., g++)
- [libcurl](https://curl.se/libcurl/) installed
- Internet connection (for location API)

### 🖥 Linux / WSL
```bash
sudo apt install libcurl4-openssl-dev
g++ -std=c++17 -o autoconnect src/*.cpp -lcurl
./autoconnect
Windows (MinGW or Git Bash)
Download and install libcurl

Use:

bash
Copy
Edit
g++ -std=c++17 -Iinclude -o autoconnect src/*.cpp -lcurl
autoconnect.exe
🧪 Sample Usage
pgsql
Copy
Edit
==== AutoConnect Menu ====
1. Student - Request Ride
2. Driver - Accept Ride
3. Exit
Choice: 1

--- Student Ride Request ---
Enter your name: Riya
Enter your pickup location name: Admin Block
Coordinates fetched: (12, 80)
Enter urgency (1 to 5): 5
Ride request submitted!
Driver logs in and sees the most urgent + nearby request:

yaml
Copy
Edit
--- Driver Login ---
Enter your name: Ravi
Enter your current location name: Library
Coordinates fetched: (12, 80)

Nearest urgent request:
Student: Riya
Urgency: 5
Distance: 0
Accept this ride? (y/n): y
Ride accepted.
Location Search API (Nominatim)
AutoConnect uses:
https://nominatim.openstreetmap.org/search?q=PLACE_NAME&format=json&limit=1
 No API key required
 Example input: Main Gate, Hostel, CSE Department

 Notes
API uses latitude & longitude, rounded to integer (for simplified distance calc).

OpenStreetMap API has rate limits (1 request/sec). Avoid spamming requests.

Add delays for production use or consider local cache of frequent locations.

 References
OpenStreetMap Nominatim API

libcurl

nlohmann JSON for C++

👨‍💻 Developer
Made with ❤️ for a college mini-project
Vinuta Sampagavi — 2025


