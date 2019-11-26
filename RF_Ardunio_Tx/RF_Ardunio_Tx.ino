#include <VirtualWire.h>
const int ledPin = 13;
char *data;
void setup() 
{
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop()
{
  data="f";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  digitalWrite(ledPin,HIGH);
  delay(2000);
  data="b";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  digitalWrite(ledPin,LOW);
  delay(2000);
}
