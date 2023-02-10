#ifndef JoystickButton_h
#define JoystickButton_h

#include "Arduino.h"
#include "UniversalGamepadBase.h"
#include "DebouncedButton.h"

class JoystickButton : public DebouncedButton
{
public:
    JoystickButton(uint8_t pin, uint8_t pinMode, UniversalGamepadBase *Gamepad, uint8_t buttonIndex);
    virtual void read();
    virtual void read(bool triggerOnChange);

private:
    UniversalGamepadBase *Gamepad;
    uint8_t buttonIndex;
};

#endif