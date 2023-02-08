#include "Arduino.h"
#include "DebouncedButton.h"



DebouncedButton::DebouncedButton(uint8_t pin, uint8_t pPinMode) : debouncer(10)
{
  pinMode(pin, pPinMode);
  _pin = pin;
  _pinMode = pPinMode;

  _buttonState = pPinMode == INPUT_PULLUP ? HIGH : LOW;
  _lastButtonState = _buttonState;
}

  void DebouncedButton::setChangeCallback(ButtonStateChanged changedcallback)
  {
    this->changedcallback = changedcallback;
  }

void DebouncedButton::read()
{
  read(true);
}

void DebouncedButton::read(bool triggerOnChange)
{
  // read the state of the switch uint8_to a local variable:
  uint8_t reading = digitalRead(_pin);
  // check to see if you just pressed the button
  // (i.e. the input went from HIGH to LOW), and you've waited long enough
  // since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:
  if (reading != _lastButtonState)
  {
    // reset the debouncing timer
    debouncer.reset();
  }

  if (debouncer.debounce())
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != _buttonState)
    {
      _buttonState = reading;
      if (isPressed())
      {
        // pressed down
        _wasPressedInLast = false;
      }
      else
      {
        // released
        _wasPressedInLast = true;
      }
    }
    else
    {
      //
      if (isPressed())
      {
        _wasPressedInLast = true;
      }
      else
      {
        _wasPressedInLast = false;
      }
    }
  }

  if (wasReleased() || pressDownStarted()) {
    if (triggerOnChange && changedcallback != NULL && changedcallback != nullptr)
    {
      changedcallback(isPressed());
    }
  }

  // save the reading. Next time through the loop, it'll be the _lastButtonState:
  _lastButtonState = reading;
}

bool DebouncedButton::pressDownStarted()
{
  return isPressed() && !_wasPressedInLast;
}

bool DebouncedButton::isPressed()
{
  return (_pinMode == INPUT ? _buttonState == HIGH : _buttonState == LOW);
}

bool DebouncedButton::wasReleased()
{
  return !isPressed() && _wasPressedInLast;
}