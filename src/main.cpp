#include <Arduino.h>
#include "input/driver.h"
#include "ui/display_driver/display_driver.h"

/**
 * @brief Helper function to convert ButtonType enum to a human-readable string.
 */
const char* buttonToString(ButtonType type) {
    switch (type) {
        case ButtonType::UP:     return "UP";
        case ButtonType::DOWN:   return "DOWN";
        case ButtonType::LEFT:   return "LEFT";
        case ButtonType::RIGHT:  return "RIGHT";
        case ButtonType::CENTER: return "CENTER";
        case ButtonType::MENU:   return "MENU";
        case ButtonType::BACK:   return "BACK";
        default:                 return "NONE";
    }
}

// Global instances
InputDriver input;
DisplayDriver display;

void setup() {
    // Initialize Serial communication
    Serial.begin(115200);
    while (!Serial) {
        ; // Wait for serial port to connect (needed for native USB boards)
    }

    Serial.println("\n============================================");
    Serial.println("   ESP32-S3 WiFi Security Tool: V1-Alpha    ");
    Serial.println("============================================\n");

    // 1. Initialize the Display first (The "Visual" layer)
    Serial.println("Initializing Display Driver...");
    display.begin();

    // 2. Initialize the Input (The "Physical" layer)
    Serial.println("Initializing Input Driver...");
    input.begin();

    Serial.println("\n--------------------------------------------");
    Serial.println("  SUCCESS: Setup Complete!                  ");
    Serial.println("  Check your Serial Monitor for feedback.    ");
    Serial.println("--------------------------------------------\n");
}

void loop() {
    // Check if a button is currently pressed
    ButtonType pressed = input.getPressedButton();

    // If a button was pressed (not NONE)
    if (pressed != ButtonType::NONE) {
        Serial.print(">>> EVENT: [ ");
        Serial.print(buttonToString(pressed));
        Serial.println(" ] <<<<");

        // A simple visual "blink" in the logs
        display.printTest(buttonToString(pressed));

        // Debounce/Wait to prevent flood
        delay(200); 
    }

    // Small delay to keep the CPU from running at full speed
    delay(10);
}
