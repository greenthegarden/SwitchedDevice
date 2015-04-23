#ifndef __SWITCHEDDEVICE_H__
#define __SWITCHEDDEVICE_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define ON  HIGH
#define OFF LOW


#define USE_TIME false

#if USE_TIME
#include "Time.h"
#endif


class SwitchedDevice
{
public:
  SwitchedDevice(byte pin = 0, boolean initial_state = OFF);
private:
  byte    _pin;
  boolean _initial_state;
  unsigned long _last_on = 0;
  unsigned long _last_off = 0;
#if USE_TIME
  time_t _last_time_on = 0;
  time_t _last_time_off = 0;
#endif
public:
  byte pin();
  unsigned long last_on();
  unsigned long last_off();
#if USE_TIME
  time_t last_time_on();
  time_t last_time_off();
#endif
  byte state();
  byte switchOn();
  byte switchOff();
  byte switchState();
};


#endif

