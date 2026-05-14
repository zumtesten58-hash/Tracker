## Wiring Diagrams

### Tracker
| Component | ESP32-C3 Pin |
| :--- | :--- |
| LoRa DX-LR22 (RX) | GPIO 21 (TX) |
| LoRa DX-LR22 (TX) | GPIO 20 (RX) |
| LoRa M0 | GPIO 6 |
| LoRa M1 | GPIO 7 |
| LoRa AUX | GPIO 10 |
| GPS (RX) | GPIO 5 (TX) |
| GPS (TX) | GPIO 4 (RX) |
| BMP280/AHT20 (SCL) | GPIO 9 |
| BMP280/AHT20 (SDA) | GPIO 8 |
| Battery Voltage (with a voltage divider) | GPIO 0 |
| Power | 3.3V / GND |

### Ground Station
| Component | ESP32-C3 Pin |
| :--- | :--- |
| LoRa DX-LR22 (RX) | GPIO 21 (TX) |
| LoRa DX-LR22 (TX) | GPIO 20 (RX) |
| LoRa M0 | GPIO 6 |
| LoRa M1 | GPIO 7 |
| LoRa AUX | GPIO 10 |
| GPS (RX) | GPIO 5 (TX) |
| GPS (TX) | GPIO 4 (RX) |
