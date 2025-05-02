# Gas Leakage Detection and Alert System using ESP8266 & Blynk

This project is a real-time gas leakage detection system using an ESP8266 microcontroller and the Blynk IoT platform. The system detects gas levels using a gas sensor (connected to analog pin A0) and sends alerts to the user's phone through the Blynk app when unsafe levels are detected.

## 🚨 Features

- Real-time gas monitoring using an analog gas sensor
- Cloud connectivity via Blynk for remote alerts
- Sends notifications via Blynk Event when gas leakage is detected
- Sensor data visualization in the Blynk app (on Virtual Pin V0)

## 🔧 Hardware Required

- ESP8266 NodeMCU board
- Gas sensor (e.g., MQ-2)
- Micro USB cable
- Wi-Fi connection

## 🧠 How It Works

1. The gas sensor continuously reads analog values from the environment.
2. The ESP8266 sends this data to the Blynk app using a virtual pin.
3. If the analog value exceeds a defined threshold (set to `20` in this code), a gas alert is triggered.
4. Blynk logs an event and sends a push notification to the user's mobile.

## 📲 Blynk Setup

1. Install the Blynk IoT app on your mobile.
2. Create a new Template:
   - **Template ID**: Use the one from your code.
   - **Template Name**: "Gas Leakage"
3. Add a datastream on **Virtual Pin V0**.
4. Create an event named `gas_alert` under Events in your Blynk template.
5. Use your `BLYNK_AUTH_TOKEN`, `WiFi SSID`, and `WiFi Password` in the code.

## 🧑‍💻 Code Overview

```cpp
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Gas Leakage"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

// WiFi credentials
char ssid[] = "Your_SSID";
char pass[] = "Your_Password";
