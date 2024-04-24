#include <Adafruit_LiquidCrystal.h>

#define debug 0

const int moisture=A1;

//setup pin
Adafruit_LiquidCrystal lcd(0);

void setup() {
 //setup LCD 1602
 lcd.begin(16, 2);
 Serial.begin(9600);
 pinMode(moisture,INPUT);
}
void loop() {
  float getVol=analogRead(moisture);
  if(debug)
  {
    Serial.print(getVol);
    Serial.print("\n");
  }
  
  int DoAm=getVol*100.0/876.0;
  
  if(DoAm>70)
  {
 	lcd.setCursor(1,0);
 	lcd.print(DoAm);
    lcd.print(" %   ");
    lcd.setCursor(1,1);
    lcd.print("THUA NUOC    ");
  }
  
  if(DoAm<60)
  {
 	lcd.setCursor(1,0);
 	lcd.print(DoAm);
    lcd.print(" %   ");
    lcd.setCursor(1,1);
    lcd.print("THIEU NUOC    ");
  }
  
  if(DoAm>=60&&DoAm<=70)
  {
 	lcd.setCursor(1,0);
 	lcd.print(DoAm);
    lcd.print(" %   ");
    lcd.setCursor(1,1);
    lcd.print("DU NUOC    ");
  }
  
  delay(5000);
}