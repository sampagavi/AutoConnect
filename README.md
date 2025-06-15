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
│   └── User.h
├── src/
│   ├── GeoUtils.cpp
│   ├── RideRequest.cpp
│   ├── User.cpp
│   └── main.cpp
├── README.md
└── .gitignore

---

## ⚙️ How to Run

### 🔧 Requirements
- C++17 compiler (e.g., g++)
- [libcurl](https://curl.se/libcurl/) installed
- Internet connection (for location API)
### 🐧 Linux / WSL

```bash
sudo apt install libcurl4-openssl-dev
g++ -std=c++17 -o autoconnect src/*.cpp -lcurl
./autoconnect
```
### Windows (MinGW or Git Bash)
- Download and install libcurl for Windows from:https://curl.se/windows/
- Compile

```bash
g++ -std=c++17 -o autoconnect src/*.cpp -lcurl
autoconnect.exe
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
  




















