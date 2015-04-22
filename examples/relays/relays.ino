#include <SwitchedDevice.h>


// a relay is a switchedDevice
typedef SwitchedDevice Relay; 


// define an individual relay
Relay relay1(1);


// define an array of relays
Relay relays[] = { Relay(2, ON),
                   Relay(3, OFF),
                   Relay(4, OFF),
                   Relay(5, ON),
                  };


/*--------------------------------------------------------------------------------------
 setup()
 Called by the Arduino framework once, before the main loop begins
 --------------------------------------------------------------------------------------*/
void setup()
{
                   
  Serial.begin(9600);
  
  Serial.print("relay1 is connected to pin ");
  Serial.print(relay1.pin());
  Serial.print(" and is ");
  if (relay1.state())
    Serial.println(" ON");
  else
    Serial.println(" OFF");
    
  for (byte idx=0; idx<(sizeof(relays)/sizeof(Relay)); idx++)
  {
   Serial.print("Relay[");
   Serial.print(idx);
   Serial.print("] is connected to pin ");
   Serial.print(relays[idx].pin());
   Serial.print(" and is ");
   if (relays[idx].state())
     Serial.println(" ON");
   else
     Serial.println(" OFF");
  }
  
}


/*--------------------------------------------------------------------------------------
 loop()
 Arduino main loop
 --------------------------------------------------------------------------------------*/
void loop()
{
  // nothing to do here!!
}
