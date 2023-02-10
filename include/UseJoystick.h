#ifndef __USE_JOYSTICK_
    #if defined(__AVR_ATmega32U4__) || defined(ARDUINO_AVR_MICRO) || defined(__AVR_ATmega16U4__)
        #define __USE_LEONARDO
        #define __USE_JOYSTICK_
        #include <Joystick.h>
    #elif ARDUINO_USB_MODE
        #define __USE_JOYSTICK_
        #define __USE_BLE_JOYSTICK
        #include <BleGamepad.h>
    #elif defined(ESP32)
        #define __USE_JOYSTICK_
        #define __USE_USB_JOYSTICK
        #include "USB.h"
        #include "USBHIDGamepad.h"
    #endif
#endif