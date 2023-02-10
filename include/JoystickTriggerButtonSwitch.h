#ifndef JoystickTriggerButtonSwitch_h
#define JoystickTriggerButtonSwitch_h

#include "Arduino.h"
#include "TriggerButtonSwitch.h"
#include "UniversalGamepadBase.h"
#include "Debouncer.h"

class JoystickTriggerButtonSwitch : public TriggerButtonSwitch
{
private:
    UniversalGamepadBase *Gamepad;

public:
    JoystickTriggerButtonSwitch(uint8_t pin, uint8_t pinMode, UniversalGamepadBase *Gamepad, uint8_t buttonIndex);
    void read();
};

#endif