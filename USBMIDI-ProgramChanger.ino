#include <USBComposite.h>

uint8_t BUTTONS[] = {PB12, PB13, PB14, PB15};
int g_nProgram = -1;

USBMIDI midi;

void setup() {
  Serial.end();
  for(int i = 0; i < sizeof(BUTTONS); ++i)
    pinMode(BUTTONS[i], INPUT_PULLUP);
  USBComposite.setProductId(0x0031);
  USBComposite.setManufacturerString("riban");
  USBComposite.setProductString("riban Program Changer");
  midi.begin();
  while(!USBComposite);
}

void loop() {
  for(int i=0; i < sizeof(BUTTONS); ++i)
  {
    if(i != g_nProgram && digitalRead(BUTTONS[i]) == LOW)
    {
      g_nProgram = i;
      midi.sendProgramChange(0, i);
    }
  }
}
