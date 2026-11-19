#include "display_driver.h"
#include <SPI.h>

// The pins from your hardware setup
#define PIN_MOSI 11
#define PIN_MISO 13
#define PIN_SCK  12
#define PIN_CS   10
#define PIN_DC   9
#define PIN_RST  8

DisplayDriver::DisplayDriver() {
}

void DisplayDriver::begin() {
    // Initialize SPI with the pins you provided
    // Syntax: SPI.begin(sck, miso, mosi, cs)
    SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_CS);
    
    // Hardware Reset Sequence (Crucial for getting out of the "White Screen")
    pinMode(PIN_RST, OUTPUT);
    pinMode(PIN_DC, OUTPUT);

    Serial.println("Display: Starting Reset Sequence...");
    digitalWrite(PIN_RST, LOW);  // Pull low to reset
    delay(100);
    digitalWrite(PIN_RST, HIGH); // Release reset
    delay(100);

    Serial.println("Display: Hardware handshake initiated.");
}

void DisplayDriver::clear(uint16_t color) {
    // Placeholder for the 'fillScreen' command logic
    Serial.print("Display: Clearing screen to color 0x");
    Serial.println(color, HEX);
}

void DisplayDriver::printTest(const char* text) {
    Serial.print("Display: [");
    Serial.print(text);
    Serial.println("]");
}
