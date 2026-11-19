#include "driver.h"

// Define the pins based on our brainstormed mapping
// Up: 1, Down: 2, Left: 3, Right: 5, Center: 6, Menu: 7, Back: 15
static const uint8_t BUTTON_PINS[7] = {1, 2, 3, 5, 6, 7, 15};
static const ButtonType BUTTON_TYPES[7] = {
    ButtonType::UP, 
    ButtonType::DOWN, 
    ButtonType::LEFT, 
    ButtonType::RIGHT, 
    ButtonType::CENTER, 
    ButtonType::MENU, 
    ButtonType::BACK
};

InputDriver::InputDriver() {
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        _buttons[i].pin = BUTTON_PINS[i];
        _buttons[i].type = BUTTON_TYPES[i];
    }
}

void InputDriver::begin() {
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        pinMode(_buttons[i].pin, INPUT_PULLUP);
    }
}

ButtonType InputDriver::getPressedButton() {
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        // If the pin is LOW, it's pressed (because of INPUT_PULLUP)
        if (digitalRead(_buttons[i].pin) == LOW) {
            // A small delay for software-level debouncing 
            // In a real high-speed loop, we'd use a timer-based debounce.
            delay(50); 
            return _buttons[i].type;
        }
    }
    return ButtonType::NONE;
}
