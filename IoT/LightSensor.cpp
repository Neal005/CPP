const int ldrPin = A0;
const int ledPin = 8;


int ldrValue;
int ledBrightness;

void setup() {
  
  pinMode(ldrPin,INPUT);

  
  pinMode(ledPin,OUTPUT);
}

void loop() {
  
  ldrValue = analogRead(ldrPin);

 
  ledBrightness = map(ldrValue, 0, 1023, 0, 255);

  
  analogWrite(ledPin, ledBrightness);
}