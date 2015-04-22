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

byte SwitchedDevice::state()
{
  return(digitalRead(this->_pin));
}

byte SwitchedDevice::switchOn()
{
  if ( state() )
    digitalWrite(this->_pin, HIGH);
  if ( state() )
    return 1;
  else
    return 0;
}

byte SwitchedDevice::switchOff()
{
  if ( !state() )
    digitalWrite(this->_pin, LOW);
  if ( !state() )
    return 1;
  else
    return 0;
}

byte SwitchedDevice::switchState()
{
  if ( state() )
    return( switchOff() );
  else
    return( switchOn() );
}
