/*
    Code by : Projects_learner
    Project name : OLED Dispaly using Ardino UNO
    Modified Date : 06-06-2024
    Website : https://projectslearner.com/learn/arduino-uno-oled-display
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Function to draw a heart shape
void drawHeart(int16_t x, int16_t y) 
{
  display.fillCircle(x, y, 3, WHITE);
  display.fillCircle(x + 6, y, 3, WHITE);
  display.fillTriangle(x - 3, y + 2, x + 9, y + 2, x + 3, y + 12, WHITE);
}

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  // Draw heart shape
  drawHeart(64, 16);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40, 40);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
}

void loop() {
  // Nothing to do here
}
