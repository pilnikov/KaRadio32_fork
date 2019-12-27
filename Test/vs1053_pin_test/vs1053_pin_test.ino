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
#include "Arduino.h"

#define SPI_MOSI      23
#define SPI_MISO      19
#define SPI_SCK       18
#define VS1053_CS     15
#define VS1053_DCS     2
#define VS1053_DREQ    4
#define VS1053_RST    12

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200); //Serial monitor start


  // initialize digital pin.
  pinMode( SPI_MOSI, OUTPUT);
  pinMode( SPI_MISO, INPUT);
  pinMode( SPI_SCK, OUTPUT);
  pinMode( VS1053_CS, OUTPUT);
  pinMode( VS1053_DCS, OUTPUT);
  pinMode( VS1053_DREQ, INPUT);
  pinMode( VS1053_RST, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(SPI_MOSI, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(SPI_SCK, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_CS, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_DCS, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_RST, HIGH);   // turn the LED on (HIGH is the voltage level)

  int InputState = digitalRead(SPI_MISO);
  Serial.print("MISO = ");
  Serial.println(InputState);

  InputState = digitalRead(VS1053_DREQ);
  Serial.print("DREQ = ");
  Serial.println(InputState);

  delay(1000);                       // wait for a second

  digitalWrite(SPI_MOSI, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(SPI_SCK, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_CS, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_DCS, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(VS1053_RST, LOW);   // turn the LED on (HIGH is the voltage level)

  InputState = digitalRead(SPI_MISO);
  Serial.print("MISO = ");
  Serial.println(InputState);

  InputState = digitalRead(VS1053_DREQ);
  Serial.print("DREQ = ");
  Serial.println(InputState);


delay(1000);                       // wait for a second
}
