#include <LiquidCrystal.h>
#define debug 1

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
  float moisture=analogRead(analogMInput)*100.0/539.0;
  if(debug){ Serial.print("Moisture: "); Serial.println(analogRead(analogMInput));}
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" Centigrade");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("Temper: ");
  lcd.print(temperature);
  lcd.print(char(178));
  lcd.print("C ");
  lcd.setCursor(1,1);
  lcd.print("Moist: ");
  lcd.print(moisture);
  lcd.print(" %  ");
}