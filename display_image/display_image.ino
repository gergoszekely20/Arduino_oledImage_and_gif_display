#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);
  delay(250);
  display.begin(0x3c, true); 
  display.clearDisplay();
}

void loop()
{
    uint8_t picture[1024];
    Serial.readBytes(picture, sizeof(picture));
    display.drawBitmap(0, 0, picture, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
    display.display();

}
