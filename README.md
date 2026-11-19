# ESP32-S3 WiFi Security/Hacking Device

A custom handheld WiFi security auditing tool built around the ESP32-S3 and a 3.5" display.

## Hardware Specs
- **Microcontroller:** ESP32-S3 (N16R8)
- **Display:** 3.5 inch LCD (via 26-pin connector)
- **Input:** 7x Push buttons (D-pad + Center/Action)

## Pinout Mapping
| 26 pin connector / Display pin | Function | ESP32-S3 (Suggested) |
|---|---|---|
| 2 or 4 | 5V | 5V |
| 6, 9, 14, 20, 25 | GND | GND |
| 19 | MOSI (LCD + touch) | GPIO11 |
| 21 | MISO (touch) | GPIO13 |
| 23 | SCK (LCD + touch) | GPIO12 |
| 24 | LCD CS | GPIO10 |
| 18 | RS (DC) | GPIO9 |
| 22 | RST | GPIO8 |
| 26 | Touch CS | GPIO14 |
| 11 | Touch IRQ | GPIO4 |

## Input Mapping (V1)
| Button Function | Suggested GPIO | Type |
|---|---|---|
| **Up** | `GPIO 1` | Digital In (Pull-up) |
| **Down** | `GPIO 2` | Digital In (Pull-up) |
| **Left** | `GPIO 3` | Digital In (Pull-up) |
| **Right** | `GPIO 5` | Digital In (Pull-up) |
| **Center (Select)** | `GPIO 6` | Digital In (Pull-up) |
| **Menu / Mode** | `GPIO 7` | Digital In (Pull-up) |
| **Back / Exit** | `GPIO 15` | Digital In (Pull-up) |

## Roadmap
- [x] Brainstorming Phase
- [x] Feature Definition (V1: Scanner)
- [x] Project Scaffolding (Folder Structure & Initial config)
- [ ] Hardware Verification (Display & Basic UI)
- [ ] Input Logic/Driver Implementation
- [ ] WiFi Scanner Prototype (V1 Goal)
- [ ] Packet Capture & Handshake Logic
- [ ] Enclosure/Physical Build
