#include <LiquidCrystal.h>
#define debug 0
#define Motor 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int analogTInput=A0,analogMInput=A1;

void setup()
{
 	lcd.begin(16,2);
 	Serial.begin(9600);
}
void loop()
{
  if(debug){Serial.print("Analog reading: ");Serial.println(analogRead(analogTInput));}
  float miliVolt = analogRead(analogTInput)*5.0/1024.0;
  float temperature = (miliVolt-0.5)*100;
  int moisture=analogRead(analogMInput)*100.0/539.0;
  if(debug){ Serial.print("Moisture: "); Serial.println(analogRead(analogMInput));}
  if(debug)
  {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" Centigrade");
  }
  lcd.setCursor(1,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(char(178));
  lcd.print("C ");
  lcd.setCursor(0,1);
  lcd.print(moisture);
  lcd.print("%   ");
  lcd.setCursor(6,1);
  if(moisture<=40)
  {
    digitalWrite(Motor,HIGH);
    lcd.print("Motor: On  ");
  }
  if(moisture>65) 
  {
    digitalWrite(Motor,LOW);
    lcd.print("Motor: Off ");
  }
  delay(500);
}