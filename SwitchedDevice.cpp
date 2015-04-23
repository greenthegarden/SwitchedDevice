#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "SwitchedDevice.h"


SwitchedDevice::SwitchedDevice(byte pin, boolean initial_state)
{
  _pin = pin;
  _initial_state = initial_state;

  pinMode(this->_pin, OUTPUT);
  digitalWrite(this->_pin, this->_initial_state);
}

byte SwitchedDevice::pin()
{
  return(this->_pin);
}

unsigned long SwitchedDevice::last_on()
{
  return(this->_last_on);
}

unsigned long SwitchedDevice::last_off()
{
  return(this->_last_off);
}

#if USE_TIME
time_t SwitchedDevice::last_time_on()
{
  return(this->_last_time_on);
}

time_t SwitchedDevice::last_time_off()
{
  return(this->_last_time_off);
}
#endif

byte SwitchedDevice::state()
{
  return(digitalRead(this->_pin));
}

byte SwitchedDevice::switchOn()
{
  if ( !state() )
  {
    digitalWrite(this->_pin, HIGH);
    if ( state() )
    {
      this->_last_on = millis();
#if USE_TIME
      this->_last_time_on = now();
#endif
      return 1;
    }
    else
      return 0;
  }
  return 0;   
}

byte SwitchedDevice::switchOff()
{
  if ( state() )
  {
    digitalWrite(this->_pin, LOW);
    if ( !state() )
    {
      this->_last_off = millis();
#if USE_TIME
      this->_last_time_off = now();
#endif
      return 1;
    }
    else
      return 0;
  }
  return 0;
}

byte SwitchedDevice::switchState()
{
  if ( state() )
    return( switchOff() );
  else
    return( switchOn() );
}
