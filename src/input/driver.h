#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>

/**
 * @brief Enum representing the different physical buttons on the device.
 */
enum class ButtonType {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    CENTER,
    MENU,
    BACK,
    NONE
};

/**
 * @brief Represents a single physical push button.
 */
struct Button {
    uint8_t pin;            // The GPIO pin number
    ButtonType type;        // The logical function of the button
};

/**
 * @brief InputDriver class to handle all hardware-level button logic.
 */
class InputDriver {
public:
    InputDriver();
    
    // Initializes all pins as INPUT_PULLUP
    void begin();

    // Returns the type of button that was just pressed (if any)
    ButtonType getPressedButton();

private:
    // We'll store our buttons in a fixed array for efficient iteration
    static const uint8_t NUM_BUTTONS = 7;
    Button _buttons[NUM_BUTTONS];

    // Internal helper to debounce/check a single button
    bool isPressed(uint8_t pin);
};

#endif // DRIVER_H
