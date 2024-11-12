/*
* Name: clock and temp project
* Author: Victor Huke & alexandar drobnjak
* Date: 2024-10-10
* Description: This project uses a ds3231 to measure time and displays the time to an 1306 oled display,
* Further, it measures temprature with a analog temprature module and displays a mapped value to a 9g-servo-motor
*/

#include <RTClib.h>
#include <Wire.h>
#include <U8glib.h>
#include <Servo.h>

RTC_DS3231 rtc;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
Servo myServo;
float temperature;
const int buttonPin = 4;
int buttonPressCount = 0;
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 10;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin(); 
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  u8g.setFont(u8g_font_unifont);
  myServo.attach(9);
  myServo.write(90); 
}

String getTime() {
  DateTime now = rtc.now();
  return (String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()));
}

void oledWrite(String text, float temp, int pressCount) {
  String temp_str = String(temp, 2);
  String pressCount_str = String(pressCount);

  u8g.firstPage();
  do {
    u8g.drawStr(34, 20, text.c_str());
    u8g.drawStr(34, 40, temp_str.c_str());
    u8g.drawStr(34, 60, pressCount_str.c_str());
  } while (u8g.nextPage());
}

void servoWrite(float temp) {
  float baseTemperature = 25.0;  
  float angle = 90 + (temp - baseTemperature) * 5 / 0.25; 
  angle = constrain(angle, 0, 180);
  myServo.write(angle);
}

float getTemp() {
  return rtc.getTemperature();
}

void loop() {
  temperature = getTemp();
  int reading = digitalRead(buttonPin);
//ja pallar inte
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        buttonPressCount++;
      }
    }
  }

  lastButtonState = reading;
  oledWrite(getTime(), temperature, buttonPressCount);
  servoWrite(temperature);
 //i love deepwoken <3
  delay(20);
}

