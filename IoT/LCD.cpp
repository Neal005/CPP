//include lib of LCD
#include <LiquidCrystal.h>

//setup pin
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 //setup LCD 1602
 lcd.begin(16,2);
}
void loop() {
 // move curso to col 0 row 1
 lcd.setCursor(1,0);
 // print to LCD
 lcd.print("Hello World!");
}