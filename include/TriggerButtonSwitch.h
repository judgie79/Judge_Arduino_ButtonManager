#ifndef TriggerButtonSwitch_h
#define TriggerButtonSwitch_h

#include "Arduino.h"
#include "DebouncedButton.h"
#include "Debouncer.h"

class TriggerButtonSwitch: public DebouncedButton
{
private:
    /* data */
public:
    TriggerButtonSwitch(uint8_t pin, uint8_t pinMode);
    virtual void begin();
    virtual void read();
    uint8_t buttonIndex;
    Debouncer debouncer;
    bool hasBeenTriggered;
};

#endif