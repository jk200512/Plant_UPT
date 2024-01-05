#include <Arduino.h>
#include <time.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int waiting_time_ms = 2000;

  int level_dry = 500;
  int level_wet = 330;

  int relay_pin = 8;
  pinMode(relay_pin, OUTPUT); // TODO: Tõsta setupisse


  int sensor_0_val = analogRead(0); // attached to water tube
  int sensor_1_val = analogRead(1); // "starter"
  /*int Value2 = analogRead(2);*/

  Serial.print("wait in ms: ");
  Serial.print(waiting_time_ms);
  Serial.print("; ");
  Serial.println(sensor_1_val);

  if (sensor_1_val > level_wet) {
    digitalWrite(relay_pin, HIGH); // Turn ON
    delay(waiting_time_ms);
    digitalWrite(relay_pin, LOW); // Turn OFF
    delay(5000);
  } else {
    digitalWrite(relay_pin, LOW); // Turn OFF
  }
  
//  if (sensor_0_val < level_wet){  
//    digitalWrite(relay_pin, LOW); // Turn OFF
//  }
  
//  delay(waiting_time_ms);
}

  /* int Dry1 = 520;
  int Dry2 = 430;
  int Moist1 = 429;
  int Moist2 = 350;
  int Wet = 350;
  int WetAF = 260; */
  

  /*  digitalWrite(Relay, HIGH);  //Turn off relay
  delay(2000);
  digitalWrite(Relay, LOW);    //Turn on relay
  delay(2000);   */
 
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


  // Täiendkontroll, et mootor ei tööta kauem kui 5 sec 
  // Kui viimasest kastmisest on möödas on x min, siis ei kasta