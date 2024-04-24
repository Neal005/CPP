#define led_1 12
#define led_2 11
#define led_3 10
#define led_4 9
#define led_5 8
#define debug 0

int Delay=700,mode=0,temp=0;;

void turnOffAll()
{
  char num;
  for(int i=led_5;i<=led_1;i++)
    digitalWrite(i, LOW);
  Serial.println("Turn off all");
  delay(Delay);
}

void turnOnAll()
{
  Serial.println("Turn on all");
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
}

void flash()
{
  Serial.println("Flash");
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(Delay);
  digitalWrite(led_5, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_1, LOW);
  delay(Delay);
}

void cycle()
{
  Serial.println("Cycle");
  digitalWrite(led_1, HIGH);
  delay(Delay);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(Delay);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(Delay);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, HIGH);
  delay(Delay);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, HIGH);
  delay(Delay);
  digitalWrite(led_5, LOW);
  delay(Delay);
}

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
  if(Serial.available()>0)
  {
    mode=Serial.read();
    
    if(mode==45)
    {
      Delay+=100;
      Serial.print(Delay); Serial.println(" ms");
      mode=temp;
    }

    if(mode==43&&Delay>0)
    {
      Delay-=100;
      Serial.print(Delay); Serial.println(" ms");
      mode=temp;
    }
    
    if(mode==49)
    {
      turnOnAll();
      temp=mode;
    }
    
    if(mode!=49&&mode!=45&&mode!=43) turnOffAll();
    
    if(mode==50)
    {
      while(Serial.available()==0)
      {
      	temp=50;
      	if(debug){Serial.print("Temp variable: "); Serial.println(temp);}
      	mode=Serial.read();
      	if(debug){Serial.print("Mode: "); Serial.println(mode);}
      	flash();
      }
    }

    if(mode==51)
    {
      while(Serial.available()==0)
      {
        temp=51;
      	if(debug){Serial.print("Temp variable: "); Serial.println(temp);}
        mode=Serial.read();
      	if(debug){Serial.print("Mode: "); Serial.println(mode);}
        cycle();
      }
    }
    
    if(mode==101||mode==69||mode==81||mode==113)
      turnOffAll();
  }
}