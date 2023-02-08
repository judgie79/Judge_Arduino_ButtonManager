#ifndef TriggerButtonSwitch_h
#define TriggerButtonSwitch_h

#include "Arduino.h"
#include "DebouncedButton.h"
#include "UseJoystick.h"
#include "Debouncer.h"

class TriggerButtonSwitch: DebouncedButton
{
private:
    /* data */
public:
    TriggerButtonSwitch(uint8_t pin, uint8_t pinMode);
    
#ifdef __USE_JOYSTICK_
    TriggerButtonSwitch(uint8_t pin, uint8_t pinMode, Joystick_ *joystick, uint8_t buttonIndex);
#endif
    virtual void begin();
    virtual void read();
    
#ifdef __USE_JOYSTICK_
    Joystick_ *joystick;
#endif
    uint8_t buttonIndex;
    Debouncer debouncer;
    bool hasBeenTriggered;
};

#endif