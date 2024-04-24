#define led_1 12
#define led_2 11
#define led_3 10
#define led_4 9
#define led_5 8

void setup()
{
  Serial.begin(9600);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);
}

void loop()
{
  //left to right
  digitalWrite(led_1, HIGH);
  delay(300);
  digitalWrite(led_1, LOW);
  
  digitalWrite(led_2, HIGH);
  delay(300);
  digitalWrite(led_2, LOW);
  
  digitalWrite(led_3, HIGH);
  delay(300);
  digitalWrite(led_3, LOW);
  
  digitalWrite(led_4, HIGH);
  delay(300);
  digitalWrite(led_4, LOW);
  
  digitalWrite(led_5, HIGH);
  delay(300);
  digitalWrite(led_5, LOW);
  delay(300);
  
  //right to left
  digitalWrite(led_5, HIGH);
  delay(300);
  digitalWrite(led_5, LOW);
  
  digitalWrite(led_4, HIGH);
  delay(300);
  digitalWrite(led_4, LOW);
  
  digitalWrite(led_3, HIGH);
  delay(300);
  digitalWrite(led_3, LOW);
  
  digitalWrite(led_2, HIGH);
  delay(300);
  digitalWrite(led_2, LOW);
  
  digitalWrite(led_1, HIGH);
  delay(300);
  digitalWrite(led_1, LOW);
  delay(300);
  
  //middle to side
  digitalWrite(led_3, HIGH);
  delay(300);
  digitalWrite(led_3, LOW);
  
  digitalWrite(led_2, HIGH);
  
  digitalWrite(led_4, HIGH);
  delay(300);
  digitalWrite(led_2, LOW);
  digitalWrite(led_4, LOW);
  
  digitalWrite(led_5, HIGH);
  
  digitalWrite(led_1, HIGH);
  delay(300);
  digitalWrite(led_5, LOW);
  digitalWrite(led_1, LOW);
  delay(300);
  
  //side to middle
  digitalWrite(led_5, HIGH);
  
  digitalWrite(led_1, HIGH);
  delay(300);
  digitalWrite(led_5, LOW);
  digitalWrite(led_1, LOW);
  
  digitalWrite(led_2, HIGH);
  
  digitalWrite(led_4, HIGH);
  delay(300);
  digitalWrite(led_2, LOW);
  digitalWrite(led_4, LOW);
  
  digitalWrite(led_3, HIGH);
  delay(300);
  digitalWrite(led_3, LOW);
  delay(300);
}