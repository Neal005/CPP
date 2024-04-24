#define debug 0

const int analogInput=A0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(debug){Serial.print("Analog reading: ");Serial.println(analogRead(analogInput));}
  float miliVolt = analogRead(analogInput)*5.0/1024.0;
  float temperature = (miliVolt-0.5)*100;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" Centigrade");
  delay(1000);
}