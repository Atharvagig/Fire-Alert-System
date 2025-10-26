# 🔥 Fire Alert System (ESP32 + Blynk IoT)

A smart fire detection and alerting system built using **ESP32**, **Flame Sensor**, **Buzzer**, **LED**, and the **Blynk IoT Platform**.  
It detects fire in real time and sends an **instant push notification** to your smartphone via Blynk Cloud.

---

## 🧠 Project Overview

This IoT-based fire alert system continuously monitors for flame using a flame sensor.  
When fire is detected:
- The **LED** turns on.  
- The **buzzer** sounds.  
- A **notification** is sent instantly to your **Blynk mobile app**.

It can be deployed in homes, labs, and offices for early fire detection and safety automation.

---

## ⚙️ Components Used

| Component | Description |
|------------|-------------|
| ESP32 | Main microcontroller with Wi-Fi |
| Flame Sensor | Detects infrared light from fire |
| LED | Visual alert |
| Buzzer | Audible alert |
| Blynk IoT | Cloud platform for monitoring and notifications |

---

## 📲 Features

- 🔥 Real-time fire detection  
- ☁️ Cloud connectivity via Blynk IoT  
- 📱 Instant push notifications on mobile  
- 💡 LED indicator for fire status  
- 🔊 Audible buzzer alert  

---

## 🧩 Circuit Connections

| Component | ESP32 Pin |
|------------|-----------|
| Flame Sensor OUT | GPIO 4 |
| LED | GPIO 2 |
| Buzzer | GPIO 5 |
| VCC | 3.3V / 5V |
| GND | GND |

---

## 🧾 Arduino Code

The full source code is available in the file **`fire_alert.ino`**.  
It includes:
- Wi-Fi configuration  
- Blynk template setup  
- Flame detection logic  
- Instant push notifications  

---

## 🚀 Setup Instructions

1. Open the project in **Arduino IDE**.  
2. Install the following libraries:
   - `Blynk` (IoT version)
   - `WiFi.h` (comes with ESP32 board)  
3. Update the following in your code:
   ```cpp
   char ssid[] = "YourWiFiName";
   char pass[] = "YourWiFiPassword";
   #define BLYNK_AUTH_TOKEN "YourBlynkDeviceKey"
