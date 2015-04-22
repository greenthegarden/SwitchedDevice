#ifndef __SWITCHEDDEVICE_H__
#define __SWITCHEDDEVICE_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define ON  HIGH
#define OFF LOW 


class SwitchedDevice
{
public:
  SwitchedDevice(byte pin = 0, boolean default_state = OFF);
private:
  byte    _pin;
  boolean _default_state;
public:
  byte state();
  byte switchOn();
  byte switchOff();
};


#endif
