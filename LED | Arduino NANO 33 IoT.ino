#include <ArduinoBLE.h>

//Everything is in milliseconds, adding up to whole seconds
//This is the duration of a dot
const int dotDuration = 1000;
//This is the duration of a dash
const int dashDuration = 3*dotDuration;
//This will be the duration of spaces between letters
const int spaceDuration = 3*dotDuration;

//This assumes that the button is connected to D13
const int buttonPin = 2;

//This is the flag to control the blinking
bool trueBlink = true;

//These are the functions for lighting up the LED for dots, dashes and space between letters 
void dotBlink()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(dotDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}
void dashBlink()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}
void spaceBlink()
{
  delay(spaceDuration);
}


//The following is functions for the individual letters of my name
//Blink letter D
void blinkD()
{
  dashBlink();
  dotBlink();
  dotBlink();
  spaceBlink();
}
//Blink letter A
void blinkA()
{
  dotBlink();
  dashBlink();
  spaceBlink();
}
//Blink letter N
void blinkN()
{
  dashBlink();
  dotBlink();
  spaceBlink();
}
//Blink letter I
void blinkI()
{
  dotBlink();
  dotBlink();
  spaceBlink();
}
//Blink letter E
void blinkE()
{
  dotBlink();
  spaceBlink();
}
//Blink letter L
void blinkL()
{
  dotBlink();
  dashBlink();
  dotBlink();
  dotBlink();
  spaceBlink();
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH && trueBlink)
  {
    blinkD();
    blinkA();
    blinkN();
    blinkI();
    blinkE();
    blinkL();
    trueBlink = false;
  }
}
