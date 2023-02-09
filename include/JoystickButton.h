#ifndef JoystickButton_h
#define JoystickButton_h

#include "Arduino.h"
#include "UseJoystick.h"

#include "DebouncedButton.h"

class JoystickButton : DebouncedButton
{
public:
    JoystickButton(uint8_t pin, uint8_t pinMode);
#ifdef __USE_JOYSTICK_
    JoystickButton(uint8_t pin, uint8_t pinMode, Joystick_ *joystick, uint8_t buttonIndex);
#endif
    virtual void begin();
    virtual void read();
    virtual void read(bool triggerOnChange);

private:
#ifdef __USE_JOYSTICK_
    Joystick_ *joystick;
#endif
    uint8_t buttonIndex;
};

#endif