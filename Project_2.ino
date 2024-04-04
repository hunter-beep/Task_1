// C++ code
// Aim:
//   To check the surrounding temperature and humidity.
//   The buzzer goes off(along wth the led) when the conditions arenot met.
//   Both the conditions and the tone of the buzzer can be set by the user
#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);
int tempsensor=A0;
int moisturesensor=A1;
float moisture;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  //lcd.backlight();
}

void loop()
{
  int value=analogRead(tempsensor);
  
  float volt= value*4.68;
  volt=volt/1024.0;
  
  float temp=(volt-0.5)*100;
  //Serial.print(temp);
  //Serial.println(" degrees C\n");
  
  int moisturevalue=analogRead(A1);
  moisture=((moisturevalue/539.00)*100);
  //Serial.print("\n Mositure value is ");
  //Serial.print(moisture);
  //Serial.print("%");
  if(moisture<50 || temp>50 || temp<20) // INitial buzzer conditions
  {
    tone(13,500,300);
    digitalWrite(12,HIGH);
    delay(1000);
    //lcd.setCursor(0,0);
    //lcd.print("ALERT");
    //lcd.setCursor(0,1);
    //lcd.print("Adjust Temp/Humidity");
  }
    
  lcd.setCursor(0,0);
  lcd.print("Temp(C) Moist(%)");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.setCursor(8,2);
  lcd.print(moisture);
    
  //lcd.print("");
  //delay(100);

}