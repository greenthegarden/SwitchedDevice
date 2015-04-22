#include "SwitchedDevice.h"

typedef SwitchedDevice Relay;  // a relay is a switchedDevice

Relay relay1(1);
Relay relay2(2);
Relay relay3(3);
Relay relay4(4);



/*--------------------------------------------------------------------------------------
 setup()
 Called by the Arduino framework once, before the main loop begins
 --------------------------------------------------------------------------------------*/
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.print("Relay 1 is ");
  if (relay1.state())
    Serial.println(" ON");
  else
    Serial.println(" OFF");
}

/*--------------------------------------------------------------------------------------
 loop()
 Arduino main loop
 --------------------------------------------------------------------------------------*/
void loop()
{
  // put your main code here, to run repeatedly:

}
