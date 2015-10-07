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
int y;
int P;
// constants won't change. They're used here to
// set pin numbers:
const int rockP = 2;     // the number of the pushbutton pin
const int scissorsP = 4;     // the number of the pushbutton pin
const int paperP = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
byte x = 0;
// variables will change:
int rockState = 0;         // variable for reading the pushbutton status
int scissorsState = 0;         // variable for reading the pushbutton status
int paperState = 0;         // variable for reading the pushbutton status
int P1;
int P2;
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(rockP, INPUT_PULLUP);
  pinMode(paperP, INPUT_PULLUP);
  pinMode(scissorsP, INPUT_PULLUP);
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(8);
  x = 4;
  Wire.write(x);
  Wire.endTransmission();
  P = 0;
  P1 = 0;
  P2 = 0;
}

void loop() {
  prepare();
  readbutton();
  
}


void prepare()
{
  switch (P)
  {
    case (0):
    P++;
    break;
    case (1):
    Wire.beginTransmission(8);
    x = 5;
    Wire.write(x);
    Wire.endTransmission();
    P++;
    break;
    case (2):
    P++;
    Wire.beginTransmission(8);
    x = 6;
    Wire.write(x);
    if (P1 == 3)
      {
        switch (P2)
        {
        case (1):
        x = 2;
        break;
        case (2):
        x = 1;
        break;
        case (3):
        x = 3;
        break;
        }
      }
   else if (P1 == 2)
     {
       switch (P2)
        {
        case (1):
        x = 1;
        break;
        case (2):
        x = 3;
        break;
        case (3):
        x = 2;
        break;
        }
     }
    else if (P1 == 1)
     {
       switch (P2)
        {
        case (1):
        x = 3;
        break;
        case (2):
        x = 2;
        break;
        case (3):
        x = 1;
        break;
        }
     }
    Wire.write(x);
    Wire.endTransmission();
    break;
  }
  
}
void readbutton()
{
  y = 1;
  do
  {
  // read the state of the pushbutton value:
  rockState = digitalRead(rockP);
  scissorsState = digitalRead(scissorsP);
  paperState = digitalRead(paperP);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (rockState == LOW) 
  {
    x = 1;
    Serial.println("rock");
    y = 0;
    if (P1 == 0)
    {
      P1 = x;
    }
    else
    {
    P2 = x;
    }
  } 
  else if (paperState == LOW)
  {
    x = 2;
    Serial.println("paper");
    y = 0;
    if (P1 == 0)
    {
      P1 = x;
    }
    else
    {
    P2 = x;
    }
  }
  else if (scissorsState == LOW)
  {
    x = 3;
    Serial.println("scissors");
    y = 0;
    if (P1 == 0)
    {
      P1 = x;
    }
    else
    {
    P2 = x;
    }
  }
  } while (y != 0);
  delay(1000);
}



