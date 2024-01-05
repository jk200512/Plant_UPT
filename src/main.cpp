#include <Arduino.h>
#include <time.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  /* int Dry1 = 520;
  int Dry2 = 430;
  int Moist1 = 429;
  int Moist2 = 350;
  int Wet = 350;
  int WetAF = 260; */
  
  int Value0 = analogRead(0);
  int Value1 = analogRead(1);
  int Value2 = analogRead(2);
  int Relay = 8;
  pinMode(Relay, OUTPUT);

  if (Value0 = 300)
  {
  delay(1000);
  }
  else 
  {
  digitalWrite(Relay, HIGH);  
  delay(2000);
  digitalWrite(Relay, LOW);    
  delay(2000);   
  } 
 /* int Value3 = analogRead(3);*/
 
 /* Serial.print(millis());
  Serial.print(": ");
  
  Serial.print(Value0);
  Serial.print(" ");

  Serial.print(Value1);
  Serial.print(" ");
  Serial.print(Value2);
  Serial.print(" ");

  Serial.print(Value3);

  Serial.println();*/

  /* if ((Value < Dry1) and (Value > Dry2))
  {
    Serial.print("Dry, ");
    Serial.println(Value);
  }
  else if ((Value < Moist1) and (Value > Moist2))
  {
    Serial.print("Moist, ");
    Serial.println(Value);
  }
  else if ((Value < Wet) and (Value > WetAF))
  {
    Serial.print("Wet, ");
    Serial.println(Value);
  }
  else
  {
    Serial.print("Out of bounds");
  } */

  

  /*delay(600000);*/
}
