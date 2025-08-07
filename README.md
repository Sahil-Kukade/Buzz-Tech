# 🐝 BuzzTech: IoT-Based Real-Time Bee Health Monitoring System

A smart IoT-enabled system built using **ESP8266**, **Blynk IoT platform**, and **multiple sensors** to monitor the health of bee hives in real-time. It measures **temperature**, **humidity**, and **sound frequency** to detect anomalies and alerts users visually (LEDs), audibly (buzzer), and remotely via the Blynk app.

---

## 🚀 Features

- 📲 **Remote Monitoring** using Blynk App
- 🌡️ **Temperature and Humidity Sensing** via DHT11
- 🎵 **Sound Frequency Monitoring** using analog sound sensor
- 🚦 **Visual Alerts** using RGB LED indicators
- 🔔 **Buzzer Alert** for critical health deviations
- 🤖 **Servo Motor** activation on critical alert
- 📤 **Real-Time Data Push** to Blynk every 2 seconds

---

## 🛠️ Hardware Requirements

| Component            | Description                        |
|---------------------|------------------------------------|
| NodeMCU ESP8266     | Microcontroller with WiFi support  |
| DHT11 Sensor        | For Temperature and Humidity       |
| Analog Sound Sensor | For hive sound/frequency analysis  |
| RGB LEDs            | Red, Green, Blue indicators        |
| Buzzer              | Audio alert                        |
| Servo Motor         | For physical movement on alert     |
| Jumper Wires        | For connections                    |
| Breadboard          | For prototyping                    |

---

## 📱 Blynk Configuration

1. Create a new Blynk Template:
   - **Template ID**: `TMPL3AxROQdEB`
   - **Template Name**: `Quickstart Template`
   - **Auth Token**: Copy it and replace in the code

2. Add 3 Virtual Pins in Blynk App:
   - `V1` → Temperature
   - `V2` → Humidity
   - `V3` → Sound Frequency

---

## 🔌 Pin Connections

| Sensor/Device     | NodeMCU Pin |
|------------------|-------------|
| DHT11             | D1          |
| Sound Sensor      | A0          |
| Red LED           | D2          |
| Green LED         | D3          |
| Blue LED          | D4          |
| Buzzer            | D5          |
| Servo Motor       | D6          |

---

## 🔧 Setup Instructions

1. Install the following Arduino libraries:
   - `ESP8266WiFi`
   - `Blynk`
   - `DHT sensor library`
   - `Adafruit Unified Sensor`
   - `Servo`

2. Flash the provided `.ino` file (`bee_health_monitor.ino`) to your NodeMCU.

3. Open Serial Monitor at 9600 baud rate to observe live sensor values.

---

## 📊 Thresholds

| Parameter     | Normal Range        |
|---------------|---------------------|
| Temperature   | 0°C to 33°C         |
| Humidity      | 40% to 80%          |
| Sound Freq.   | 20 to 90 (analog)   |

- **Green LED**: One parameter abnormal  
- **Blue LED**: Two parameters abnormal  
- **Red LED + Buzzer + Servo**: All three parameters abnormal

---

## 🖥️ Design



![Hardware Setup](setup.jpg)


