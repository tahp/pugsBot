# ESP32-S3 WiFi Security/Hacking Device

A custom handheld WiFi security auditing tool built around the ESP32-S3 and a 3.5" display.

## Hardware Specs
- **Microcontroller:** ESP32-S3
- **Display:** 3.5 inch LCD (via 26-pin connector)
- **Input:** Planned 5-7 push buttons (D-pad + Center/Action)

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

## Roadmap
- [x] Brainstorming Phase
- [ ] Hardware Verification (Display & Basic UI)
- [ ] Input Logic (D-pad/Button Navigation)
- [ ] WiFi Scanner Prototype
- [ ] Packet Capture & Handshake Logic
- [ ] Enclosure/Physical Build
