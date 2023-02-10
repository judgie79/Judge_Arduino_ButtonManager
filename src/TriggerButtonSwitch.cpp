#include "TriggerButtonSwitch.h"

TriggerButtonSwitch::TriggerButtonSwitch(uint8_t pin, uint8_t pinMode) : DebouncedButton(pin, pinMode)
{

}

void TriggerButtonSwitch::begin()
{

}

void TriggerButtonSwitch::read()
{
    DebouncedButton::read(false);
    if (pressDownStarted() || wasReleased())
    {
      hasBeenTriggered = true;
      debouncer.reset();
    }

      if (hasBeenTriggered && debouncer.debounce())
      {
        hasBeenTriggered = false;
        if (changedcallback != NULL) {
            changedcallback(!isPressed());
        }
      }
}