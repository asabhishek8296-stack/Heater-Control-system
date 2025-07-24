# Heater Control System – ESP32

## Overview
A temperature-based heater control system using ESP32 and DS18B20 sensor. The system simulates a heater (LED) and overheat alert (buzzer), and logs states via Serial Monitor.

## Features
- Tracks 5 system states: Idle, Heating, Stabilizing, Target Reached, Overheat
- Controls heater and buzzer based on temperature
- Real-time temperature logging over Serial

## Components
- ESP32
- DS18B20 temperature sensor
- LED (heater)
- Buzzer (overheat indicator)

## Wokwi Simulation
https://wokwi.com/projects/437335397449721857

## Files
- `sketch.ino` – Source code
- `diagram.json` – Circuit layout for Wokwi
- `HeaterControlSystem.pdf` – Project report
- `README.md` – This file
