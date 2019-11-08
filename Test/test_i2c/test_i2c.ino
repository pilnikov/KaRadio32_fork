#include <Wire.h>

byte error, address;
int nDevices;  //Кол-во найденных устройств

void setup() {
  Wire.begin(33, 32);
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
}

void loop() {
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++ )  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error == 4)    {
      Serial.print("Unknow error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  Wire.beginTransmission(0x1a);
  Wire.write(0x123); // reset register pointer
  Wire.endTransmission();
  uint8_t rv = Wire.requestFrom(0x1a, 0x41);
  Serial.print("41 =");
  Serial.println(rv);
  rv = Wire.requestFrom(0x1a, 0x14);
  Serial.print("14 =");
  Serial.println(rv); 
  rv = Wire.requestFrom(0x1a, 0x15);
  Serial.print("15 =");
  Serial.println(rv); 
  rv = Wire.requestFrom(0x1a, 0x16);
  Serial.print("16 =");
  Serial.println(rv);

  Wire.beginTransmission(0x1a);
  Wire.write(0x16); // reset register pointer
  Wire.write(0x8); // reset register pointer
  Wire.endTransmission();

  rv = Wire.requestFrom(0x1a, 0x16);
  Serial.print("16_2 =");
  Serial.println(rv);


  delay(5000);  // Ждем 5 сек. до следующего сканирования
}
