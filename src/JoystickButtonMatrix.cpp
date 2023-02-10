#include "JoystickButtonMatrix.h"

JoystickButtonMatrix::JoystickButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row, uint8_t buttonStartIndex, UniversalGamepadBase *Gamepad)
  : ButtonMatrix(cols, rows, col, row) {
    this->startIndex = startIndex;
    this->Gamepad = Gamepad;
}

JoystickButtonMatrix::JoystickButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row, uint8_t buttonStartIndex, ButtonMatrixChanged changedCallback, UniversalGamepadBase *Gamepad)
  : ButtonMatrix(cols, rows, col, row, changedCallback) {
    this->startIndex = startIndex;
    this->Gamepad = Gamepad;
}

void JoystickButtonMatrix::onStateChange(uint8_t buttonIndex, uint8_t state) {

  if (isPressed(buttonIndex)) {
      Gamepad->press(buttonIndex + startIndex);
  } else {
      Gamepad->release(buttonIndex + startIndex);
  }

  ButtonMatrix::onStateChange(buttonIndex + startIndex, state);
}
