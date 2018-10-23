/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
const int BLINK_LED = 10;

const int FADE_AMOUNT = 5;
int brightness = 0;
int direction = 1; 

void increaseBrightness() {
  brightness += FADE_AMOUNT;

  if (brightness > 255) {
    brightness = 255;
  }
  analogWrite(BLINK_LED, brightness);
}

void decreaseBrightness() {
  brightness -= FADE_AMOUNT;

  if (brightness < 0) {
    brightness = 0;
  }
  analogWrite (BLINK_LED, brightness);
  
}

void setup() {
  pinMode(BLINK_LED, OUTPUT);  // Our LED pin is output
}
void loop() {
  if (direction == 1 && brightness >= 255) {
    direction = 0;
  }
  else if (direction == 0 && brightness <= 0) {
    direction = 1;
  }
  
  if (direction == 1) {
    increaseBrightness();
  }
  
  else {
    decreaseBrightness();
  }
  
  delay(30);
}
