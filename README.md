# 🚖 AutoConnect – Real-Time Ride Request System for College Students

**AutoConnect** is a terminal-based C++ project that enables **students to raise urgent ride requests** and helps **auto drivers** respond based on **urgency** and **proximity**.

---

## 💡 Why AutoConnect?

In large college campuses, students often struggle to find transportation in urgent situations. **AutoConnect** provides a simple ride-request system that:

- Matches students with **available auto drivers**
- Considers **urgency level**
- Calculates **nearest auto** using real-time location lookup via API

---

## 🔧 Features

- 📝 **Request Ride** – Students can enter name, pickup, destination, urgency
- 📍 **Location Search** – Supports location by name using [OpenCage API](https://opencagedata.com/)
- ⚡ **Priority System** – Urgency-driven (scale of 1 to 5)
- 🚕 **Driver Interface** – Drivers view and accept closest & most urgent requests
- ⭐ **Feedback (optional enhancement)**
- 📊 **Sorted Request Queue** – Based on urgency and proximity

---

## 📂 Project Structure

AutoConnect/
│
├── include/
│ ├── AutoConnect.h
│ ├── GeoUtils.h
│ ├── RideRequest.h
│ └── User.h
│
├── src/
│ ├── GeoUtils.cpp
│ ├── RideRequest.cpp
│ ├── User.cpp
│ └── main.cpp
│
├── .gitignore
└── README.md

pgsql
Copy
Edit

---

## 🌍 Location API Setup

We use the **OpenCage Geocoding API** to convert user-input location names (e.g., "Library", "Main Gate") into latitude/longitude.

### 🔑 Get Free API Key

1. Go to [OpenCage](https://opencagedata.com/)
2. Create a free account and get your API key
3. In `GeoUtils.cpp`, replace this line:
```cpp
std::string apiKey = "YOUR_API_KEY"; // Replace with your actual key


