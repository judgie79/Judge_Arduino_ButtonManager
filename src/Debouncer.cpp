#include "Debouncer.h"

Debouncer::Debouncer(uint16_t delay)
{
    _debounceDelay = (unsigned long)delay;
}

Debouncer::Debouncer()
{
}

void Debouncer::begin(uint16_t delay)
{
    _debounceDelay = delay;
}

bool Debouncer::debounce()
{
    if (millis() - _lastPoll > _debounceDelay)
    {
        _lastPoll = millis();
        return true;
    }
    return false;
}

void Debouncer::reset()
{
    _lastPoll = millis();
}