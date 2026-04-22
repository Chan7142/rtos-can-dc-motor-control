#include <SPI.h>

#define ADXL345_SpeedMaximum 5000000 //ADXL345 의 최대 속도는 5Mhz
#define ADXL345_Speed 100000 //사용할 ADXL345 의 SPI 통신 속도 1Mhz
#define SPI_CS_Pin 10
byte receive = 0;
byte address = 0x00;
// ADXL345 의 clock polarity 는 CPOL = 1, CPHA = 1 
// 따라서 아두이노의 모드는 SPI_MODE3
void CS_ON(){
  digitalWrite(SPI_CS_Pin, LOW);
}
void CS_OFF(){
  digitalWrite(SPI_CS_Pin, HIGH);
}

void setup() {
  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  Serial.begin(9600);
  pinMode(SPI_CS_Pin, OUTPUT);
  CS_ON();
  SPI.transfer(0x2D); // 주소
  SPI.transfer(0x08); // 데이터 (Measure 모드 ON)
  CS_OFF();
  delay(100);
}

void loop() {
  CS_ON();
  SPI.transfer(address | 0x80);
  receive = SPI.transfer(0xAA);

  Serial.println(receive);
  CS_OFF();
  delay(500);

}