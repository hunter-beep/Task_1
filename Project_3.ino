// C++ code
// Aim to calculate height and weight, then find body mass index
// Errors might be present in calculation of weight
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
int trigpin=5;
int echopin=3;
int forcesensor=A0;
int BMI;
float force;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setBacklight(1);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(forcesensor,OUTPUT);
}

void loop()
{
  float forcevalue = analogRead(forcesensor);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  //delay(300);
  //digitalWrite(echopin,LOW);
  int time=pulseIn(echopin,HIGH);
  float distance=time*0.034/2;
  distance=300-distance; //Placing the sensor at a height of 3m
  // then subtracting to calculate height
  //Serial.println(distance);
  force = (10.0/41.0)*(forcevalue);
  lcd.setCursor(0,0);
  lcd.print("Hgt(cm) :");
  lcd.print(distance);
  lcd.setCursor(0,1);
  lcd.print("Wt(kg)  :");
  lcd.print(force);
  delay(500);
  Serial.println(force);
  lcd.setCursor(0,0);
  int BMI= force/((distance/100)*(distance/100));
  lcd.print("BMI :");
  lcd.print(BMI);
  lcd.print("           ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  delay(500);
}
