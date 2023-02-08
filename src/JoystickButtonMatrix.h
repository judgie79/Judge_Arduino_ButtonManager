#ifndef JoystickButtonMatrix_h
#define JoystickButtonMatrix_h

#include <Arduino.h>
#include "UseJoystick.h"
#include "ButtonMatrix.h"

class JoystickButtonMatrix : public ButtonMatrix {
protected:
  uint8_t startIndex;
  void onStateChange(uint8_t buttonIndex, uint8_t state);
#ifdef __USE_JOYSTICK_
  Joystick_ *joystick;
#endif
public:
#ifdef __USE_JOYSTICK_
  JoystickButtonMatrix(Joystick_ *joystick, uint8_t buttonStartIndex);
#endif
  JoystickButtonMatrix(uint8_t buttonStartIndex);
  virtual void begin(uint8_t cols, uint8_t rows, uint8_t *col, uint8_t *row, ButtonMatrixChanged changedcallback);
  virtual void read();
};

#endif