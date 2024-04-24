#define green 12
#define yellow 11
#define red 10

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(20000);
  digitalWrite(green, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(5000);
  digitalWrite(yellow, LOW);
  
  digitalWrite(red, HIGH);
  delay(20000);
  digitalWrite(red, LOW);
}