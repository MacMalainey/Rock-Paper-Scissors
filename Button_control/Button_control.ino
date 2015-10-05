#include <Wire.h>

/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int rockP = 2;     // the number of the pushbutton pin
const int scissorsP = 4;     // the number of the pushbutton pin
const int paperP = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int rockState = 0;         // variable for reading the pushbutton status
int scissorsState = 0;         // variable for reading the pushbutton status
int paperState = 0;         // variable for reading the pushbutton status
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(rockP, INPUT_PULLUP);
  pinMode(paperP, INPUT_PULLUP);
  pinMode(scissorsP, INPUT_PULLUP);
  Wire.begin();
  Serial.begin(9600);
}
byte x = 0;
void loop() {
  // read the state of the pushbutton value:
  rockState = digitalRead(rockP);
  scissorsState = digitalRead(scissorsP);
  paperState = digitalRead(paperP);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (rockState == LOW) 
  {
    Wire.beginTransmission(8); // transmit to device #8
    x = 1;
    Wire.write(x);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    Serial.println("rock");
  } 
  else if (paperState == LOW)
  {
    Wire.beginTransmission(8); // transmit to device #8
    x = 2;
    Wire.write(x);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    Serial.println("paper");
  }
  else if (scissorsState == LOW)
  {
    Wire.beginTransmission(8); // transmit to device #8
    x = 3;
    Wire.write(x);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    Serial.println("scissors");
  }
  delay(50);
}
