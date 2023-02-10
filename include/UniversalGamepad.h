#ifndef UniversalGamePad_h
#define UniversalGamePad_h

#include "Arduino.h"
#include "UseJoystick.h"
#include "UniversalGamepadBase.h"
#include "JoystickButton.h"
#include "JoystickButtonMatrix.h"
#include "JoystickTriggerButtonSwitch.h"

class UniversalGamepad : UniversalGamepadBase
{
private:
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    Joystick_ *Gamepad;
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    USBHIDGamepad *Gamepad;
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    BleGamepad *Gamepad;
#endif
    uint8_t numberOfButtons;
    uint8_t totalNumberOfButtons;
    JoystickButton **buttons;
    ButtonMatrix *matrix;
    uint8_t numberOfTriggerSwitches;
    JoystickTriggerButtonSwitch **triggerSwitches;
    UniversalGamepad(uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches);
public:
#if defined(__USE_JOYSTICK_) && defined(__USE_LEONARDO)
    UniversalGamepad(Joystick_ *Gamepad);
    UniversalGamepad(Joystick_ *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix, uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches);
#elif defined(__USE_JOYSTICK_) && defined(__USE_USB_JOYSTICK)
    UniversalGamepad(USBHIDGamepad *Gamepad);
    UniversalGamepad(USBHIDGamepad *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix,  uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches);
#elif defined(__USE_JOYSTICK_) && defined(__USE_BLE_JOYSTICK)
    UniversalGamepad(BleGamepad *Gamepad);
    UniversalGamepad(BleGamepad *Gamepad, uint8_t numberOfButtons, JoystickButton **buttons, ButtonMatrix *matrix,  uint8_t numberOfTriggerSwitches, JoystickTriggerButtonSwitch **triggerSwitches);
#endif
    virtual void begin();
    void read();
    void setAxes(int16_t x = 0, int16_t y = 0, int16_t z = 0, int16_t rZ = 0, int16_t rX = 0, int16_t rY = 0, int16_t slider1 = 0, int16_t slider2 = 0);
    void press(uint8_t b);   // press BUTTON_1 by default
    void release(uint8_t b); // release BUTTON_1 by default
    void pressSpecialButton(uint8_t b);
    void releaseSpecialButton(uint8_t b);
    void pressStart();
    void releaseStart();
    void pressSelect();
    void releaseSelect();
    void pressMenu();
    void releaseMenu();
    void pressHome();
    void releaseHome();
    void pressBack();
    void releaseBack();
    void pressVolumeInc();
    void releaseVolumeInc();
    void pressVolumeDec();
    void releaseVolumeDec();
    void pressVolumeMute();
    void releaseVolumeMute();
    void setLeftThumb(int16_t x = 0, int16_t y = 0);
    void setRightThumb(int16_t z = 0, int16_t rZ = 0);
    void setLeftTrigger(int16_t rX = 0);
    void setRightTrigger(int16_t rY = 0);
    void setTriggers(int16_t rX = 0, int16_t rY = 0);
    void setHats(signed char hat1 = 0, signed char hat2 = 0, signed char hat3 = 0, signed char hat4 = 0);
    void setHat(signed char hat = 0);
    void setHat1(signed char hat1 = 0);
    void setHat2(signed char hat2 = 0);
    void setHat3(signed char hat3 = 0);
    void setHat4(signed char hat4 = 0);
    void setX(int16_t x = 0);
    void setY(int16_t y = 0);
    void setZ(int16_t z = 0);
    void setRZ(int16_t rZ = 0);
    void setRX(int16_t rX = 0);
    void setRY(int16_t rY = 0);
    void setSliders(int16_t slider1 = 0, int16_t slider2 = 0);
    void setSlider(int16_t slider = 0);
    void setSlider1(int16_t slider1 = 0);
    void setSlider2(int16_t slider2 = 0);
    void setRudder(int16_t rudder = 0);
    void setThrottle(int16_t throttle = 0);
    void setAccelerator(int16_t accelerator = 0);
    void setBrake(int16_t brake = 0);
    void setSteering(int16_t steering = 0);
    void setSimulationControls(int16_t rudder = 0, int16_t throttle = 0, int16_t accelerator = 0, int16_t brake = 0, int16_t steering = 0);
    void sendReport();
    bool isPressed(uint8_t b); // check BUTTON_1 by default
    bool isConnected(void);
    void resetButtons();
};

#endif