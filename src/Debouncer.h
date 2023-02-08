#ifndef __DEBOUNCER_H__
#define __DEBOUNCER_H__

#include <Arduino.h>

class Debouncer {
private:
	unsigned long _lastPoll = 0;
	unsigned long _debounceDelay;
public:
	Debouncer(uint16_t delay);

	Debouncer();

	void begin(uint16_t delay) ;

	bool debounce();

	void reset();
};

#endif