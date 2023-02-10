#ifndef UniversalGamepadBase_h
#define UniversalGamepadBase_h

#include "Arduino.h"

class UniversalGamepadBase
{
private:
public:
    virtual void begin();
    virtual void read();
    virtual void setAxes(int16_t x = 0, int16_t y = 0, int16_t z = 0, int16_t rZ = 0, int16_t rX = 0, int16_t rY = 0, int16_t slider1 = 0, int16_t slider2 = 0);
    virtual void press(uint8_t b);   // press BUTTON_1 by default
    virtual void release(uint8_t b); // release BUTTON_1 by default
    virtual void pressSpecialButton(uint8_t b);
    virtual void releaseSpecialButton(uint8_t b);
    virtual void pressStart();
    virtual void releaseStart();
    virtual void pressSelect();
    virtual void releaseSelect();
    virtual void pressMenu();
    virtual void releaseMenu();
    virtual void pressHome();
    virtual void releaseHome();
    virtual void pressBack();
    virtual void releaseBack();
    virtual void pressVolumeInc();
    virtual void releaseVolumeInc();
    virtual void pressVolumeDec();
    virtual void releaseVolumeDec();
    virtual void pressVolumeMute();
    virtual void releaseVolumeMute();
    virtual void setLeftThumb(int16_t x = 0, int16_t y = 0);
    virtual void setRightThumb(int16_t z = 0, int16_t rZ = 0);
    virtual void setLeftTrigger(int16_t rX = 0);
    virtual void setRightTrigger(int16_t rY = 0);
    virtual void setTriggers(int16_t rX = 0, int16_t rY = 0);
    virtual void setHats(signed char hat1 = 0, signed char hat2 = 0, signed char hat3 = 0, signed char hat4 = 0);
    virtual void setHat(signed char hat = 0);
    virtual void setHat1(signed char hat1 = 0);
    virtual void setHat2(signed char hat2 = 0);
    virtual void setHat3(signed char hat3 = 0);
    virtual void setHat4(signed char hat4 = 0);
    virtual void setX(int16_t x = 0);
    virtual void setY(int16_t y = 0);
    virtual void setZ(int16_t z = 0);
    virtual void setRZ(int16_t rZ = 0);
    virtual void setRX(int16_t rX = 0);
    virtual void setRY(int16_t rY = 0);
    virtual void setSliders(int16_t slider1 = 0, int16_t slider2 = 0);
    virtual void setSlider(int16_t slider = 0);
    virtual void setSlider1(int16_t slider1 = 0);
    virtual void setSlider2(int16_t slider2 = 0);
    virtual void setRudder(int16_t rudder = 0);
    virtual void setThrottle(int16_t throttle = 0);
    virtual void setAccelerator(int16_t accelerator = 0);
    virtual void setBrake(int16_t brake = 0);
    virtual void setSteering(int16_t steering = 0);
    virtual void setSimulationControls(int16_t rudder = 0, int16_t throttle = 0, int16_t accelerator = 0, int16_t brake = 0, int16_t steering = 0);
    virtual void sendReport();
    virtual bool isPressed(uint8_t b); // check BUTTON_1 by default
    virtual bool isConnected(void);
    virtual void resetButtons();
};

#endif