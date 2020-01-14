
// Test for check connection between ESP and VS

// For test you must disconnect the +5v pin from VS!!!!!! GND do not disconnect!!!!
#include "Arduino.h"

#define SPI_MOSI      23
#define SPI_MISO      19
#define SPI_SCK       18
#define VS1053_CS     32
#define VS1053_DCS    33
#define VS1053_DREQ   34
#define VS1053_RST    12
#define DEL           3000

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin.
  pinMode( SPI_MISO, OUTPUT);
  pinMode( SPI_MOSI, OUTPUT);
  pinMode( SPI_SCK, OUTPUT);
  pinMode( VS1053_CS, OUTPUT);
  pinMode( VS1053_DCS, OUTPUT);
  pinMode( VS1053_DREQ, OUTPUT);
  pinMode( VS1053_RST, OUTPUT);

  digitalWrite(SPI_MOSI, LOW);   // 1
  digitalWrite(SPI_MISO, LOW);   // 2
  digitalWrite(SPI_SCK, LOW);   // 3
  digitalWrite(VS1053_CS, LOW);   // 4
  digitalWrite(VS1053_DCS, LOW);   // 5
  digitalWrite(VS1053_DREQ, LOW);   // 6
  digitalWrite(VS1053_RST, LOW);   // 7

}

// HIGH LEVEL SEQUENSE MISO -> MOSI -> SCK -> XCS -> XDCS -> DREQ -> XRST delay 3s
void loop() {
  digitalWrite(SPI_MISO, HIGH);   // 1
  delay(DEL);                       // wait for a DEL second
  digitalWrite(SPI_MISO, LOW);   // 1
  
  digitalWrite(SPI_MOSI, HIGH);   // 2
  delay(DEL);                       // wait for a DEL second
  digitalWrite(SPI_MOSI, LOW);   // 2

  digitalWrite(SPI_SCK, HIGH);   // 3
  delay(DEL);                       // wait for a DEL second
  digitalWrite(SPI_SCK, LOW);   // 3

  digitalWrite(VS1053_CS, HIGH);   // 4
  delay(DEL);                       // wait for a DEL second
  digitalWrite(VS1053_CS, LOW);   // 4

  digitalWrite(VS1053_DCS, HIGH);   // 5
  delay(DEL);                       // wait for a DEL second
  digitalWrite(VS1053_DCS, LOW);   // 5

  digitalWrite(VS1053_DREQ, HIGH);   // 6
  delay(DEL);                       // wait for a DEL second
  digitalWrite(VS1053_DREQ, LOW);   // 6

  digitalWrite(VS1053_RST, LOW);   // 7
  delay(DEL);                       // wait for a DEL second
  digitalWrite(VS1053_RST, LOW);   // 7
}
