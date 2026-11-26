# 🍳 IoT-Based Restaurant Kitchen Monitoring Using KiwisIoT

Monitor restaurant kitchen conditions in real time using ESP8266, DHT11, and MQ-135 sensors with the KiwisIoT cloud dashboard.

## 📖 About the Project

This project is designed to monitor environmental conditions inside a restaurant kitchen using IoT technology. It measures temperature, humidity, and air-quality-related sensor readings to help observe kitchen conditions remotely.

Using an ESP8266 NodeMCU, DHT11 sensor, and MQ-135 sensor, the system collects sensor data and sends it to the KiwisIoT dashboard, allowing users to monitor the kitchen environment from anywhere.

## 🛠️ Hardware Components

- ESP8266 NodeMCU
- DHT11 Temperature and Humidity Sensor
- MQ-135 Air Quality Sensor
- Jumper Wires
- USB Cable
- Breadboard (optional)

## ⚡ Features

- Real-time temperature monitoring
- Humidity monitoring
- Air-quality-related sensor readings
- Kitchen environment status monitoring
- Cloud-based dashboard visualization
- Remote monitoring using KiwisIoT

## 🔌 Circuit Connections

### DHT11 Sensor

| DHT11 | NodeMCU |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | D4 |

### MQ-135 Sensor

| MQ-135 | NodeMCU |
|---|---|
| VCC | Appropriate supply voltage |
| GND | GND |
| AOUT | A0 |

**Note:** Check the voltage range of your NodeMCU analog input before connecting the MQ-135 analog output. Use a suitable voltage divider if necessary.

## 📊 KiwisIoT Dashboard

The project sends the following information to the KiwisIoT dashboard:

- **Channel 0:** Temperature
- **Channel 1:** Humidity
- **Channel 2:** MQ-135 Sensor Reading
- **Channel 3:** Kitchen Environment Status

The dashboard helps visualize the kitchen's environmental conditions remotely.

## 🚀 How It Works

The DHT11 sensor measures the temperature and humidity inside the kitchen, while the MQ-135 sensor provides an air-quality-related analog reading.

The ESP8266 NodeMCU collects the sensor values, processes the readings, and sends the data through Wi-Fi to the KiwisIoT platform.

Users can view the collected information on their cloud dashboard and observe changes in kitchen environmental conditions.

## 🌐 KiwisIoT Integration

KiwisIoT is used to visualize the sensor readings collected by the ESP8266. By connecting the device to the cloud dashboard, users can monitor kitchen environmental data remotely.

## 🔮 Future Improvements

- Add gas-specific sensors
- Implement automated exhaust fan control
- Add alert notifications
- Improve dashboard visualization
- Add multiple sensor nodes

## ⚠️ Disclaimer

This project is an educational IoT monitoring prototype. The MQ-135 is a general-purpose gas sensor and does not provide certified gas concentration measurements or reliably identify specific gases. This project should not replace commercial kitchen safety equipment, certified gas detectors, or fire alarms.

## 📷 Project

Read the complete project tutorial on Hackster.io:

https://www.hackster.io/kirusokumar/iot-based-restaurant-kitchen-monitoring-using-kiwisiot-145f99

## 🌱 Explore KiwisIoT

I use **KiwisIoT** to connect my IoT projects with a cloud-based dashboard, making it easy to monitor sensor data and manage connected devices in real time. If you're interested in building your own IoT projects, visit the KiwisIoT website and explore the example projects to get started.

You can also explore the **Arduino IDE integration and KiwisIoT Arduino library** to learn how to connect your hardware, send sensor data, and build your own IoT applications.

**Website:** https://www.kiwisiot.in/

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

Explore the Arduino IDE and KiwisIoT library to start building your own connected projects!

---
