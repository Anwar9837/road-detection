#include <Servo.h>
Servo servo1;
int servoPin = 7;

#define sensor 9
int delay1()
{
  //unsigned int long k;
  int i,j;
  unsigned int count=0;
  for(i=0;i<500;i++)
  {
    for(j=0;j<500;j++)
    {
      if(digitalRead(sensor))
      {
        count++;
        while(digitalRead(sensor));
        delay(10);
        break;
      }
    }
  }
  return count;
}

void setup()
{
  pinMode(9, INPUT);
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  servo1.attach(servoPin);
  Serial.print("Tachometer");
  
}

void loop()
{
  unsigned int time=0, RPM=0;
  while(digitalRead(9));
   {
  Serial.print("\nReading RPM.....");
  time = delay1();
  Serial.print("\nPlease wait.....");
  RPM = (time*12);
  delay(200);
  Serial.print("\nRPM = ");
  Serial.print(RPM);
    }
  delay(500);
  servo1.write(30);
  if ((RPM > 200) && (RPM < 400))
  {
    Serial.print("\n if ");
    servo1.write(110);
  }
  else if (( RPM > 400) && (RPM < 1000))
  {
    Serial.print("\n elif1 ");
    servo1.write(30);
  }
  else if ( RPM < 200)
  {
    Serial.print("\n elif2 ");
    servo1.write(30);
  }
  else
  {
    Serial.print("\n else ");
    servo1.write(30);
  }

}