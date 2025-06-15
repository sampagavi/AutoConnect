# 🚕 AutoConnect - Urgent Ride Request System

**AutoConnect** is a terminal-based ride request and assignment system built in **C++**, designed to help **students in emergencies** quickly request rides from available **auto drivers** on campus. It features **urgency-based prioritization**, **distance-based matching**, and **live location fetching using OpenStreetMap API**.

---

## 💡 Why AutoConnect?

Students often struggle to find autos during urgent situations (medical emergencies, time-sensitive classes, etc.). AutoConnect enables:

- Students to **search locations by name** (e.g., "Main Gate", "Library")
- Auto drivers to **view and accept nearest requests**
- A **priority queue** that selects rides based on **urgency** and **proximity**

---

## ✨ Features

- 📍 **Search Location by Name** using OpenStreetMap Nominatim API
- ⚡ **Urgency-Based Priority Queue** (1 to 5)
- 📏 **Shortest Distance Matching** for drivers
- 🧑‍🎓 Students request rides from terminal
- 👨‍✈️ Auto drivers can accept rides from queue
- ✅ Clean, modular structure using C++ headers and classes

---

## 📁 Project Structure

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


