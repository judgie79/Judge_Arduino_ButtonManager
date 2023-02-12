#include "UniversalGamepad.h"

UniversalGamepad::UniversalGamepad(uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches)
{
    this->numberOfButtons = numberOfButtons;
    this->buttons = buttons;
    this->matrix = matrix;
    this->numberOfTriggerSwitches = numberOfTriggerSwitches;
    this->triggerSwitches = triggerSwitches;

    this->totalNumberOfButtons = numberOfButtons + matrix->numberOfButtons() + numberOfTriggerSwitches;
}

#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
UniversalGamepad::UniversalGamepad(Joystick_ *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches)
    : UniversalGamepad(numberOfButtons, buttons, matrix, numberOfTriggerSwitches, triggerSwitches)
{
    this->Gamepad = Gamepad;
}
UniversalGamepad::UniversalGamepad(Joystick_ *Gamepad)
{
    this->Gamepad = Gamepad;
}
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
UniversalGamepad::UniversalGamepad(USBHIDGamepad *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches)
    : UniversalGamepad(numberOfButtons, buttons, matrix, numberOfTriggerSwitches, triggerSwitches)
{
    this->Gamepad = Gamepad;
    
}
UniversalGamepad::UniversalGamepad(USBHIDGamepad *Gamepad)
{
    this->Gamepad = Gamepad;
}
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
UniversalGamepad::UniversalGamepad(BleGamepad *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches)
    : UniversalGamepad(numberOfButtons, buttons, matrix, numberOfTriggerSwitches, triggerSwitches)
{
    this->Gamepad = Gamepad;
}
UniversalGamepad::UniversalGamepad(BleGamepad *Gamepad)
{
    this->Gamepad = Gamepad;
}
#endif

void UniversalGamepad::read()
{
    for (size_t i = 0; i < numberOfButtons; i++)
    {
        buttons[i]->read();
    }

    matrix->read();

    for (size_t i = 0; i < numberOfTriggerSwitches; i++)
    {
        triggerSwitches[i]->read();
    }


}

void UniversalGamepad::begin()
{    
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->begin(true);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->begin();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    Gamepad->begin();
#endif

    for (size_t i = 0; i < numberOfButtons; i++)
    {
        
    }
    matrix->begin();

    for (size_t i = 0; i < numberOfTriggerSwitches; i++)
    {
        triggerSwitches[i]->begin();
    }
}

void UniversalGamepad::press(uint8_t index)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->pressButton(index);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->pressButton(index);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->press(index);
    }
#endif
}

void UniversalGamepad::release(uint8_t index)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->releaseButton(index);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->releaseButton(index);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->release(index);
    }
#endif
}

void UniversalGamepad::setAxes(int16_t x, int16_t y, int16_t z, int16_t rZ, int16_t rX, int16_t rY, int16_t slider1, int16_t slider2)
{

#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setXAxis(x);
    Gamepad->setYAxis(y);
    Gamepad->setZAxis(z);
    Gamepad->setRzAxis(rZ);

   // Gamepad->setAxes(x, y, z, rZ, rX, rX, slider1, slider2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->leftTrigger(rX);
    Gamepad->rightTrigger(rY);
     Gamepad->leftStick(x, y);
      Gamepad->rightStick(z, rZ);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setAxes(x, y, z, rZ, rX, rX, slider1, slider2);
    }
#endif
}

void UniversalGamepad::pressSpecialButton(uint8_t b)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //   Gamepad->pressSpecialButton(b)
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressSpecialButton(b)
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressSpecialButton(b);
    }
#endif
}

void UniversalGamepad::releaseSpecialButton(uint8_t b)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //   Gamepad->releaseSpecialButton(b)
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->releaseSpecialButton(b)
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseSpecialButton(b);
    }
#endif
}

void UniversalGamepad::pressStart()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //   Gamepad->pressStart();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
//    Gamepad->pressStart();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressStart();
    }
#endif
}

void UniversalGamepad::releaseStart()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
   //  Gamepad->re()
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->releaseStart()
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseStart();
    }
#endif
}

void UniversalGamepad::pressSelect()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    // Gamepad->press()
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->pressSelect()
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressSelect();
    }
#endif
}
void UniversalGamepad::releaseSelect()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //   Gamepad->releaseSelect()
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->()
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseSelect();
    }
#endif
}

void UniversalGamepad::pressMenu()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->pressMenu();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressMenu();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressMenu();
    }
#endif
}

void UniversalGamepad::releaseMenu()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
   // Gamepad->releaseMenu();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->releaseMenu();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseMenu();
    }
#endif
}

void UniversalGamepad::pressHome()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
 //   Gamepad->pressHome();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressHome();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressHome();
    }
#endif
}
void UniversalGamepad::releaseHome()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->releaseHome();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->releaseHome();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseHome();
    }
#endif
}

void UniversalGamepad::pressBack()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->pressBack();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //  Gamepad->pressBack();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressBack();
    }
#endif
}

void UniversalGamepad::releaseBack()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->releaseBack();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->releaseBack();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseBack();
    }
#endif
}

void UniversalGamepad::pressVolumeInc()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  // Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressVolumeInc();
    }
#endif
}

void UniversalGamepad::releaseVolumeInc()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
 //  Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressVolumeInc();
    }
#endif
}

void UniversalGamepad::pressVolumeDec()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressVolumeInc();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressVolumeInc();
    }
#endif
}

void UniversalGamepad::releaseVolumeDec()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->releaseVolumeDec();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->releaseVolumeDec();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseVolumeDec();
    }
#endif
}

void UniversalGamepad::pressVolumeMute()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->pressVolumeMute();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->pressVolumeMute();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->pressVolumeMute();
    }
#endif
}

void UniversalGamepad::releaseVolumeMute()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    //Gamepad->releaseVolumeMute();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->releaseVolumeMute();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->releaseVolumeMute();
    }
#endif
}

void UniversalGamepad::setLeftThumb(int16_t x, int16_t y)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setXAxis(x);
    Gamepad->setYAxis(y);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->leftStick(x, y);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setLeftThumb(x, y);
    }
#endif
}

void UniversalGamepad::setRightThumb(int16_t z, int16_t rZ)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setZAxis(z);
    Gamepad->setRzAxis(rZ);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->rightStick(z, rZ);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRightThumb(z, rZ);
    }
#endif
}

void UniversalGamepad::setLeftTrigger(int16_t rX)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRyAxis(rX);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->leftTrigger(rX);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setLeftTrigger(rX);
    }
#endif
}

void UniversalGamepad::setRightTrigger(int16_t rY)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRyAxis(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->rightTrigger(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRightTrigger(rY);
    }
#endif
}

void UniversalGamepad::setTriggers(int16_t rX, int16_t rY)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRyAxis(rX);
    Gamepad->setRyAxis(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->leftTrigger(rX);
    Gamepad->rightTrigger(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setTriggers(rX, rY);
    }
#endif
}

void UniversalGamepad::setHats(signed char hat1, signed char hat2, signed char hat3, signed char hat4)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(0, hat1);
    Gamepad->setHatSwitch(1, hat2);
    Gamepad->setHatSwitch(2, hat3);
    Gamepad->setHatSwitch(3, hat4);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->hat(hat1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHats(hat1, hat2, hat3, hat4);
    }
#endif
}

void UniversalGamepad::setHat(signed char hat)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(0, hat);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->hat(hat);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHat(hat);
    }
#endif
}

void UniversalGamepad::setHat1(signed char hat1)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(0, hat1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    Gamepad->hat(hat1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHat1(hat1);
    }
#endif
}

void UniversalGamepad::setHat2(signed char hat2)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(1, hat2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    // Gamepad->hat(hat1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHat2(hat2);
    }
#endif
}

void UniversalGamepad::setHat3(signed char hat3)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(2, hat3);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    // Gamepad->hat(hat3);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHat3(hat3);
    }
#endif
}

void UniversalGamepad::setHat4(signed char hat4)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setHatSwitch(3, hat4);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
   // Gamepad->hat(hat1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setHat4(hat4);
    }
#endif
}

void UniversalGamepad::setX(int16_t x)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setXAxis(x);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->leftStick(x, Gamepad->leftStick());
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setX(x);
    }
#endif
}

void UniversalGamepad::setY(int16_t y)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setYAxis(y);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setY(y);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setY(y);
    }
#endif
}

void UniversalGamepad::setZ(int16_t z)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setZAxis(z);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->setZ(z);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setZ(z);
    }
#endif
}

void UniversalGamepad::setRZ(int16_t rZ)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRzAxis(rZ);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->setRZ(rZ);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRZ(rZ);
    }
#endif
}

void UniversalGamepad::setRX(int16_t rX)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRxAxis(rX);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setRX(rX);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRX(rX);
    }
#endif
}

void UniversalGamepad::setRY(int16_t rY)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRyAxis(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->setRY(rY);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRY(rY);
    }
#endif
}
void UniversalGamepad::setSliders(int16_t slider1, int16_t slider2)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
 //   Gamepad->setSliders(slider1, slider2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setSliders(slider1, slider2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSliders(slider1, slider2);
    }
#endif
}

void UniversalGamepad::setSlider(int16_t slider)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->setSlider(slider);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setSlider(slider);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSlider(slider);
    }
#endif
}
void UniversalGamepad::setSlider1(int16_t slider1)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
  //  Gamepad->setSlider1(slider1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
 //   Gamepad->setSlider1(slider1);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSlider1(slider1);
    }
#endif
}

void UniversalGamepad::setSlider2(int16_t slider2)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
   // Gamepad->setSlider2(slider2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  // Gamepad->setSlider2(slider2);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSlider2(slider2);
    }
#endif
}
void UniversalGamepad::setRudder(int16_t rudder)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRudder(rudder);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setRudder(rudder);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setRudder(rudder);
    }
#endif
}

void UniversalGamepad::setThrottle(int16_t throttle)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setThrottle(throttle);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
   // Gamepad->setThrottle(throttle);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setThrottle(throttle);
    }
#endif
}

void UniversalGamepad::setAccelerator(int16_t accelerator)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setAccelerator(accelerator);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->setAccelerator(accelerator);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setAccelerator(accelerator);
    }
#endif
}

void UniversalGamepad::setBrake(int16_t brake)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setBrake(brake);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->(brake);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setBrake(brake);
    }
#endif
}

void UniversalGamepad::setSteering(int16_t steering)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setSteering(steering);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    // Gamepad->setSteering(steering);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSteering(steering);
    }
#endif
}

void UniversalGamepad::setSimulationControls(int16_t rudder, int16_t throttle, int16_t accelerator, int16_t brake, int16_t steering)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Gamepad->setRudder(rudder);
    Gamepad->setThrottle(throttle);
    Gamepad->setAccelerator(accelerator);
    Gamepad->setBrake(brake);
    Gamepad->setSteering(steering);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    // Gamepad->setSimulationControls(rudder, throttle, accelerator, brake, steering);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->setSimulationControls(rudder, throttle, accelerator, brake, steering);
    }
#endif
}

void UniversalGamepad::sendReport()
{
    #if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
   // Gamepad->sendReport();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->write();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        Gamepad->sendReport();
    }
#endif
    
}

bool UniversalGamepad::isPressed(uint8_t b)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    // return Gamepad->isPressed(b);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  return Gamepad->hid(b);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    if (Gamepad->isConnected())
    {
        return Gamepad->isPressed(b);
    }
#endif
    return false;
}

bool UniversalGamepad::isConnected(void)
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    return true;
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    return true;
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    return Gamepad->isConnected();
#endif
    return false;
}

void UniversalGamepad::resetButtons()
{
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    // Gamepad->res();
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
  //  Gamepad->resetButtons();
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    Gamepad->resetButtons();
#endif
}