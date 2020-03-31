#include <VirtualWire.h>

#define button 6

char *data;
int val;
int value = 0;

void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  val = digitalRead(button);
  if(val == LOW && value == 0)
  {
    data="a";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
    value = 1;
  }
  else if(val == LOW && value == 1)
  {
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
    value = 0;
  }
  delay(200);
}
