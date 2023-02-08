#include <TriggerButtonSwitch.h>

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#include <Joystick.h>
#endif

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
Joystick_ Joystick;
#endif

int pin = 0;
int buttonIndex = 0;
int pinMode = INPUT_PULLUP;

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
TriggerButtonSwitch buttonSwitch(pin, pinMode, &Joystick, buttonIndex, onSwitchChanged);
#else
TriggerButtonSwitch buttonSwitch(pin, pinMode, onSwitchChanged);
#endif

void onSwitchChanged(bool isPressed)
{
    DebugOut.debug("triggered " + String(isPressed));
}

void setup() {
    Serial.begin(9600);
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
  Joystick.begin();
#endif
    buttonSwitch.begin();
}

void loop() {
    buttonSwitch.read();
}