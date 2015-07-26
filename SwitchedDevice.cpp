#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "SwitchedDevice.h"


SwitchedDevice::SwitchedDevice(byte pin, byte initial_state)
    : _pin(pin), _initial_state(initia_state), _last_on(0), _last_off(0)
{
//    _pin = pin;
//    _initial_state = initial_state;

    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, this->_initial_state);
}

SwitchedDevice::SwitchedDevice(byte pin, byte initial_state, byte master_pin)
    : _pin(pin), _initial_state(initia_state), _master_pin(master_pin), _last_on(0), _last_off(0)
{
//    _pin = pin;
//    _initial_state = initial_state;
//    _master_pin = master_pin;

    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, this->_initial_state);
}

byte SwitchedDevice::pin()
{
    return(this->_pin);
}

byte SwitchedDevice::master_pin()
{
    return(this->_master_pin);
}

unsigned long SwitchedDevice::last_on()
{
    return(this->_last_on);
}

unsigned long SwitchedDevice::last_off()
{
    return(this->_last_off);
}

byte SwitchedDevice::state()
{
    return(digitalRead(this->_pin));
}

byte SwitchedDevice::switchOn()
{
    if (!state()) {
        digitalWrite(this->_pin, HIGH);
        if (state()) {
            this->_last_on = millis();
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
    return 0;
}

byte SwitchedDevice::switchOff()
{
    if (state()) {
        digitalWrite(this->_pin, LOW);
        if (!state()) {
            this->_last_off = millis();
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
    return 0;
}

byte SwitchedDevice::switchState()
{
    if (state()) {
        return(switchOff());
    }
    else {
        return(switchOn());
    }
}
