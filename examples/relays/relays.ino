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
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.print("Relay 1 is ");
  if (relay1.state())
    Serial.println(" ON");
  else
    Serial.println(" OFF");
    
  for (byte idx=0; idx<(sizeof(relays)/sizeof(Relay)); idx++)
  {
   Serial.print("Relay ");
   Serial.print(idx);
   Serial.print(" is ");
   if (relay1.state())
     Serial.println(" ON");
   else
     Serial.println(" OFF")
  }
  
}

/*--------------------------------------------------------------------------------------
 loop()
 Arduino main loop
 --------------------------------------------------------------------------------------*/
void loop()
{
  // put your main code here, to run repeatedly:

}
