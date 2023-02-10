#include "JoystickButton.h"

JoystickButton::JoystickButton(uint8_t pin, uint8_t pinMode, UniversalGamepadBase *Gamepad, uint8_t buttonIndex)
    : DebouncedButton(pin, pinMode)
{
    this->Gamepad = Gamepad;
    this->buttonIndex = buttonIndex;
}

void JoystickButton::read()
{
    read(true);
}

void JoystickButton::read(bool triggerOnChange)
{
    DebouncedButton::read(triggerOnChange);
    if (isPressed()) {
        Gamepad->press(buttonIndex);
    } else {
        Gamepad->release(buttonIndex);
    }
}