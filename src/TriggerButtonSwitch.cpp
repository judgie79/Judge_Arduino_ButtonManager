#include "TriggerButtonSwitch.h"

#ifdef __USE_JOYSTICK_
TriggerButtonSwitch::TriggerButtonSwitch(uint8_t pin, uint8_t pinMode, Joystick_ *joystick, uint8_t buttonIndex) : 
    DebouncedButton(pin, pinMode),
    debouncer(100)
{
    this->joystick = joystick;
    this->buttonIndex = buttonIndex;
}
#endif

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
      
#ifdef __USE_JOYSTICK_
      joystick->setButton(buttonIndex, isPressed());
#endif
      hasBeenTriggered = true;
      debouncer.reset();
    }

      if (hasBeenTriggered && debouncer.debounce())
      {
        hasBeenTriggered = false;

#ifdef __USE_JOYSTICK_        
        joystick->setButton(buttonIndex, !isPressed());
#endif
        if (changedcallback != NULL) {
            changedcallback(!isPressed());
        }
      }
}