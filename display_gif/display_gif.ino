#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const uint8_t START_BYTE = 0xAA;
const uint8_t NEW_FRAME_BYTE = 0xBB;

void setup()
{
  Serial.begin(9600);
  delay(250);
  display.begin(0x3c, true); 
  display.clearDisplay();
}

void loop()
{
  while (Serial.available() > 0) {
    uint8_t startByte = Serial.read();

    if (startByte == START_BYTE) {
      uint16_t bytesRead = 0;
      uint16_t totalBytes = SCREEN_WIDTH * SCREEN_HEIGHT / 8;
      uint8_t picture[totalBytes];

      while (bytesRead < totalBytes) {
        bytesRead += Serial.readBytes(picture + bytesRead, totalBytes - bytesRead);
      }

      display.drawBitmap(0, 0, picture, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
      display.display();
    }
  }
}
