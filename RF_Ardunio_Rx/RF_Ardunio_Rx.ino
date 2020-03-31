#include <VirtualWire.h>
#define ledPin 6

void setup()
{
    vw_set_rx_pin(11);
    vw_setup(2000);
    pinMode(ledPin, OUTPUT);
    vw_rx_start();
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='a')
      {  
       digitalWrite(ledPin,HIGH);
      }  
      else if(buf[0]=='b')
      {
       digitalWrite(ledPin,LOW);
      }
    }
}
