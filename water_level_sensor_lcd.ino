#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define led 8


int resval = 0;
int respin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.clear();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("WATER LEVEL: ");
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);

  resval = analogRead(respin);

  if (resval <= 100){
    Serial.println("Water Level: Empty");
    lcd.print("Empty             ");
    digitalWrite(led, LOW);
  }
  else if (resval > 100 && resval <= 350){
    Serial.println("Water Level: Low");
    lcd.print("Low             ");
    digitalWrite(led, LOW);
  }
  else if (resval > 350 && resval <= 400){
    Serial.println("Water Level: Medium");
    lcd.print("Medium             ");
    digitalWrite(led, HIGH);
  }
  else if (resval > 400){
    Serial.println("Water Level: High");
    lcd.print("High             ");
    digitalWrite(led, LOW);
  }
}


