#include "JoystickButton.h"

JoystickButton::JoystickButton(uint8_t pin, uint8_t pinMode)
    : DebouncedButton(pin, pinMode)
{

}
#ifdef __USE_JOYSTICK_
JoystickButton::JoystickButton(uint8_t pin, uint8_t pinMode, Joystick_ *joystick, uint8_t buttonIndex)
    : DebouncedButton(pin, pinMode)
{
    this->joystick = joystick;
    this->buttonIndex = buttonIndex;
}
#endif

void JoystickButton::read()
{
    read(true);
}

#ifdef __USE_JOYSTICK_
void JoystickButton::read(bool triggerOnChange)
{
    DebouncedButton::read(triggerOnChange);

    joystick->setButton(buttonIndex, isPressed());
    joystick->sendState();
}
#endif