#include <SoftwareSerial.h>
#include <U8glib.h>
#include <Wire.h>
#define esp01 Serial1

U8GLIB_ST7920_128X64_1X lcd(13, 11, 10);

int flag = 0;

void clear() {
  lcd.setFont(u8g_font_8x13);
  lcd.setColorIndex(0);
  lcd.drawBox(1, 1, 64, 128);
  lcd.setColorIndex(1);
}

void error() {
  lcd.setFont(u8g_font_8x13);
  lcd.drawStr(38, 20, "ERROR!");
  lcd.drawStr(45, 40, "WiFi");
  lcd.drawStr(15, 60, "Disconnected");
}

void setup() {
  Serial.begin(9600);
  esp01.begin(9600);
  Serial.println("Hello");
  Wire.begin();
}

void loop() {
  if (esp01.available())
    Serial.write(esp01.read());
  if (Serial.available())
    esp01.write(Serial.read());

}
