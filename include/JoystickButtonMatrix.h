#ifndef JoystickButtonMatrix_h
#define JoystickButtonMatrix_h

#include <Arduino.h>
#include "UniversalGamepadBase.h"
#include "ButtonMatrix.h"

class JoystickButtonMatrix : public ButtonMatrix
{
protected:
  uint8_t startIndex;
  void onStateChange(uint8_t buttonIndex, uint8_t state);
  UniversalGamepadBase *Gamepad;
public:
  JoystickButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row, uint8_t buttonStartIndex, UniversalGamepadBase *Gamepad);
  JoystickButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row,  uint8_t buttonStartIndex, ButtonMatrixChanged changedCallback, UniversalGamepadBase *Gamepad);
  virtual void read();
};

#endif