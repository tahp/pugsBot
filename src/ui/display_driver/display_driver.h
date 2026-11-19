#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <Arduino.h>

/**
 * @brief Class to handle the initialization and communication with the LCD.
 */
class DisplayDriver {
public:
    DisplayDriver();

    // Initializes the SPI bus and the LCD controller
    void begin();

    // Clears the screen with a solid color (useful for testing)
    void clear(uint16_t color);

    // A simple way to print a message for testing
    void printTest(const char* text);

private:
    // We will use these to verify the hardware is talking
    void initHardware();
};

#endif // DISPLAY_DRIVER_H
