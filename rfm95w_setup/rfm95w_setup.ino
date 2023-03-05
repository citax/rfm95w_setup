#include <SPI.h>

#define RFM95_CS 10
#define RFM95_RST 9

void setup() {
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  delay(100);
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  SPI.begin();
  SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0)); // SPI frekansı burada ayarlanmaktadır.

  // Kanal ayarını değiştir
  byte channel = 10; // Örnek olarak kanal numarası 10 olarak ayarlanmıştır.
  uint32_t freq = 902300000 + (channel * 200000);
  uint32_t frf = ((freq << 11) / 125000) & 0x00FFFFFF;
  digitalWrite(RFM95_CS, LOW);
  SPI.transfer(0x06);
  SPI.transfer((frf >> 16) & 0xFF);
  SPI.transfer((frf >> 8) & 0xFF);
  SPI.transfer(frf & 0xFF);
  digitalWrite(RFM95_CS, HIGH);

  SPI.endTransaction();
}

void loop() {
 
}
