#include <HC-SR04.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

#define echoPin 2
#define trigPin 3

HCSR04 HC = HCSR04(echoPin, trigPin);               

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(HC.showDistance(true));
  lcd.setCursor(3, 0);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print(HC.showDistance(false));
  lcd.setCursor(3, 1);
  lcd.print(" inch");
}
