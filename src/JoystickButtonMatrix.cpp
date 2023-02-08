#include "JoystickButtonMatrix.h"

JoystickButtonMatrix::JoystickButtonMatrix(uint8_t startIndex)
  : ButtonMatrix() {
  this->startIndex = startIndex;
}

#ifdef __USE_JOYSTICK_
JoystickButtonMatrix::JoystickButtonMatrix(Joystick_ *joystick, uint8_t startIndex)
  : JoystickButtonMatrix(startIndex) {
  this->joystick = joystick;
}
#endif

void JoystickButtonMatrix::begin(uint8_t cols, uint8_t rows, uint8_t *col, uint8_t *row, ButtonMatrixChanged changedcallback) {
  ButtonMatrix::begin(cols, rows, col, row, changedcallback);
}
void JoystickButtonMatrix::read() {
  ButtonMatrix::read();
}
#ifdef __USE_JOYSTICK_
void JoystickButtonMatrix::onStateChange(uint8_t buttonIndex, uint8_t state) {
  joystick->setButton(buttonIndex + startIndex, state);

  ButtonMatrix::onStateChange(buttonIndex + startIndex, state);
}
#endif
