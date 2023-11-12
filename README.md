# Automatic Tomato Plant Irrigation System

## Description
This repository contains the code for an automated irrigation system designed for tomato plants. The system is built using an Arduino Mega 2560, a soil moisture sensor (YL-69 probe with YL-38 module), a Tiny RTC I2C module with DS1307 and EEPROM 24C32, and an external 8-channel 5V relay module. The system is ideal for ensuring optimal growth conditions for tomato plants by automating the irrigation process based on soil moisture levels and time.

### Components
- **Arduino Mega 2560**: Serves as the central control unit for the system.
- **Soil Moisture Sensor (YL-69 Probe with YL-38 Module)**: This sensor setup includes a YL-69 probe with two adequately separated terminals for detecting soil moisture and a YL-38 module for signal processing. It monitors the moisture level in the soil, as detailed in the code provided in this chat.
- **Tiny RTC I2C Module (DS1307 with EEPROM 24C32)**: Provides accurate timekeeping with battery backup capability, allowing for time-based control in addition to moisture-based control. The integration of this module is detailed in the code in this chat.
- **8-Channel 5V Relay Module for Arduino**: Controls various components such as the water pump and LED lights.
- **RGB LED Lights (Common Anode)**: Used for providing supplemental lighting to the tomato plants.
- **8W Aquarium Water Pump**: Utilized for the irrigation system to water the plants when needed.

## System Operation
The irrigation system operates by reading the soil moisture level using the YL-69 probe and YL-38 module. When the moisture level falls below a predefined threshold, indicating that the soil is dry, the system activates the water pump via the relay module to water the plants. The system also deactivates the pump when the soil reaches an adequate level of moisture.

Additionally, the RGB LED lights are controlled based on the time of the day, providing supplemental lighting to the plants during specific hours. This lighting schedule is managed by the Tiny RTC I2C module, ensuring that the plants receive an optimal amount of light.

## Code
The code for this system is included in this repository. It contains the logic for reading the soil moisture levels using the YL-69 and YL-38 sensor setup, controlling the water pump, and managing the LED lighting based on the time provided by the Tiny RTC I2C module.

## Setup and Installation
For setting up the system, connect the components as described in the code comments and ensure that the Arduino Mega 2560 is programmed with the provided code. Detailed instructions on the connections and setup can be found in the code comments.

---

This system is designed to provide a hassle-free and efficient way to maintain optimal growing conditions for tomato plants, making it an ideal solution for both hobbyists and professional gardeners.
