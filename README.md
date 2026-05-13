# Tracker

## Project description:
This is a tracking device for various objects, such as drones or kites. The tracking device can transmit GPS position data over a distance of up to approximately 8 km, depending on line of sight and any obstacles. You can then see the location and distance. Under ideal conditions, the range is only around 8 kilometres.

## How it works:
You plug a USB stick containing the entire firmware into the PC. Then you plug your own ESP32-C3 Super Mini into the PC and attach the tracker to the object you wish to track. The tracker automatically sends signals to the ESP connected to the PC via a LoRa module, and these are then displayed. Ideally, it is also displayed on a map: your own location and the location of the tracker. Various settings can also be adjusted via the PC, such as the power-saving mode. On the PC, you can see the altitude, temperature, air pressure, battery voltage and the current time via a BMP280 and an AHT20 module built into the board.

## Why I built this project:
My kite flew away recently because the string snapped. Now it’s lying somewhere in the woods, high up in the trees. I haven’t been able to find it. If the kite had had a tracker, I would have been spared the whole search, because then I could have seen where it was in the software. I would simply have retrieved it. And a drone has flown away from me once before, too. It would have been handy if it had had a tracker as well, so that I could have located it.

## BOM:
| Item | Quantity | Description | Link |
| :--- | :--- | :--- | :--- |
| ESP32 C3 SuperMini | 2 | Main Controller (1x Tracker, 1x Ground Station) | [AliExpress](https://de.aliexpress.com/item/1005008498196688.html) |
| TP4056 Module | 1 | LiPo Battery Charging Module | [AliExpress](https://de.aliexpress.com/item/1005012053702082.html) |
| AHT20 + BMP280 | 1 | Temperature, Humidity & Pressure Sensor | [AliExpress](https://de.aliexpress.com/item/1005008735075401.html) |
| GPS/BDS Module | 2 | ATGM336H Navigation Modules | [AliExpress](https://de.aliexpress.com/item/1005006420287202.html) |
| DX-LR22-900T22D KIT | 1 | LoRa Wireless Modules (868MHz/900MHz) | [AliExpress](https://de.aliexpress.com/item/1005011899716097.html) |
| Battery 3.7V | 1 | 2000mAh LiPo Battery | [AliExpress](https://de.aliexpress.com/item/1005004402762404.html) |
| 10k Ohm Resistor | 2 | Resistors for battery voltage divider | [AliExpress](https://de.aliexpress.com/item/1005003923602966.html) |

## Visuals
![3D Model](./assets/3d_render.png)
![Wiring Diagram](./assets/Circuitdiagram.png)
