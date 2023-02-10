#include "JoystickTriggerButtonSwitch.h"

JoystickTriggerButtonSwitch::JoystickTriggerButtonSwitch(uint8_t pin, uint8_t pinMode, UniversalGamepadBase *Gamepad, uint8_t buttonIndex) : TriggerButtonSwitch(pin, pinMode)
{
    this->Gamepad = Gamepad;
    this->buttonIndex = buttonIndex;
}

void JoystickTriggerButtonSwitch::read()
{
    DebouncedButton::read();
    if (pressDownStarted() || wasReleased())
    {
        if (isPressed())
        {
            Gamepad->press(buttonIndex);
        }
        else
        {
            Gamepad->release(buttonIndex);
        }
        hasBeenTriggered = true;
        debouncer.reset();
    }

    if (hasBeenTriggered && debouncer.debounce())
    {
        hasBeenTriggered = false;

        if (!isPressed())
        {
            Gamepad->press(buttonIndex);
        }
        else
        {
            Gamepad->release(buttonIndex);
        }
        if (changedcallback != NULL)
        {
            changedcallback(!isPressed());
        }
    }
}