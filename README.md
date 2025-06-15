#  AutoConnect - Urgent Ride Request System

**AutoConnect** is a terminal-based ride request and assignment system built in **C++**, designed to help **students in emergencies** quickly request rides from available **auto drivers** on campus. It features **urgency-based prioritization**, **distance-based matching**, and **live location fetching using OpenStreetMap API**.

---

## Why AutoConnect?

Students often struggle to find autos during urgent situations (medical emergencies, time-sensitive classes, etc.). AutoConnect enables:

- Students to **search locations by name** (e.g., "Main Gate", "Library")
- Auto drivers to **view and accept nearest requests**
- A **priority queue** that selects rides based on **urgency** and **proximity**

---

##  Features

-  **Search Location by Name** using OpenStreetMap Nominatim API
-  **Urgency-Based Priority Queue** (1 to 5)
-  **Shortest Distance Matching** for drivers
- Students request rides from terminal
- Auto drivers can accept rides from queue
- Clean, modular structure using C++ headers and classes

---

##  Project Structure

AutoConnect/
├── include/
│   ├── AutoConnect.h
│   ├── GeoUtils.h
│   ├── RideRequest.h
│   ├── User.h
│   └── nlohmann/                
│       └── json.hpp            
├── src/
│   ├── GeoUtils.cpp
│   ├── RideRequest.cpp
│   ├── User.cpp
│   └── main.cpp
├── README.md
└── .gitignore


---

##  How to Run

### Requirements
- C++17 or newer
- libcurl (for making network requests)
- Internet connection (for fetching live coordinates)
- nlohmann/json.hpp (already included in the repo)
### Running in GitHub Codespaces (Recommended)
1. No local setup required. Just use GitHub’s built-in development environment:
2. Click the green Code button on the GitHub repo → Choose Codespaces → Create codespace.
3. Wait for the Codespace to load in the browser.
4. In the terminal, run
  ```bash
  g++ -std=c++17 -o autoconnect src/*.cpp -Iinclude -lcurl
./autoconnect
```
5. Follow the menu to simulate student and driver ride interactions.
(All dependencies including nlohmann/json.hpp are already included — no need to install anything else.)

### Running on Linux (Ubuntu or WSL)
- Install dependencies:
```bash
sudo apt update
sudo apt install g++ libcurl4-openssl-dev
```
- Clone the repo and navigate to the project folder:
 ```bash
git clone https://github.com/yourusername/AutoConnect.git
cd AutoConnect
 ```
- Compile and run the project:
```bash
g++ -std=c++17 -o autoconnect src/*.cpp -Iinclude -lcurl
./autoconnect
 ```
### Windows (MinGW or Git Bash)
- Install MinGW and make sure it's added to your PATH.
- Download and install libcurl for Windows from: https://curl.se/windows/
- Ensure nlohmann/json.hpp is in your include/ folder (already included in repo).
- Open Git Bash or terminal and navigate to the project:
```bash
git clone https://github.com/yourusername/AutoConnect.git
cd AutoConnect
 ```
- Compile and run
```bash
  g++ -std=c++17 -o autoconnect src/*.cpp -Iinclude -lcurl
  ./autoconnect.exe
```
---
## Location API
This project uses OpenStreetMap's Nominatim API to convert place names into coordinates.
For example, entering "IIT Madras" returns its latitude and longitude.
- No API key needed for basic usage.
---
## Sample Usage Flow
1. Student enters name, location name (e.g., "Central Library"), and urgency.
2. Driver logs in with name and location.
3. System calculates the best match based on urgency + proximity.
4. Driver is shown best ride → can accept or reject.
5. Feedback and further extensions can be added.
---
##  Future Improvements
- Ride history logging
- OTP verification between student & driver
- Mobile app or GUI frontend
- Map visualization
---
## Imp points
- API uses latitude & longitude, rounded to integer (for simplified distance calc)
- OpenStreetMap API has rate limits (1 request/sec). Avoid spamming requests
- Add delays for production use or consider local cache of frequent locations
---
  Created by:Vinuta Sampagavi
  




















