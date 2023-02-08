#ifndef DebouncedButton_h
#define DebouncedButton_h

#include "Arduino.h"
#include "Debouncer.h"

typedef void(*ButtonStateChanged) (bool);

class DebouncedButton {
public:
  DebouncedButton(uint8_t pin, uint8_t pinMode);
  void setChangeCallback(ButtonStateChanged changedcallback);
  virtual void read();
  virtual void read(bool triggerOnChange);
  bool pressDownStarted();
  bool isPressed();
  bool wasReleased();
private:
  uint8_t _pin;
  uint8_t _pinMode;
  uint8_t _buttonState = HIGH;              // the current reading from the input pin
  uint8_t _lastButtonState = HIGH;          // the previous reading from the input pin

  bool _wasPressedInLast;

	Debouncer debouncer;
protected:
  ButtonStateChanged changedcallback;
};

#endif