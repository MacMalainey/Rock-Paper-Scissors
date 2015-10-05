#include <LiquidCrystal.h>

// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

// all of our LCD pins
int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(lcdRSPin, lcdEPin,
                  lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

#include <Wire.h>

void setup() {
  lcd.begin(16, 8);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(1000);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
    byte c = Wire.read(); // receive byte as a character
    Serial.println(c);
    String res;
    switch (c) {
      case (1):
      res = "rock";
      break;
      case (2):
      res = "paper";
      break;
      case (3):
      res = "scissors";
      break;
    }
    lcd.setCursor(0, 0);// print the character
    lcd.clear();
    lcd.print(res);
}
