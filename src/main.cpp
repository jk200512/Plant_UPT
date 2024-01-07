#include <Arduino.h>
#include <time.h>

void setup()
{
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT); 
}
int waiting_time_ms = 10000; // aeg, mil pump töötab enne välja lülitamist (10 sec)
int suspend_time = 900000; // aeg, kui kaua arduino ootab enne uut tsükklit (15 min)
int level_dry = 500; // mulla niiskuse level cap. sensoritele
int level_wet = 330; // vee märguse nivoo torus oleva andurile
int relay_pin = 8; // relee signaali pin
int sensor_0_val = analogRead(0); // attached to water tube
int sensor_1_val = analogRead(1); // in soil
int sensor_2_val = analogRead(2); // in soil
int maxTime = 15000UL; // max aeg, mil pump võib töötada, liidan millis ajale "Unsigned Long" numbrina (ilma UL'ta on tulemused imelikud)
int previousTime = millis(); // praegune aeg

void loop()
{
  if ((sensor_1_val >= level_dry) and (sensor_2_val >= level_dry)){
    digitalWrite(relay_pin, HIGH); // Turn ON
    while (previousTime < (previousTime + maxTime)) 
    {
      if (sensor_0_val >= level_wet){
        delay(waiting_time_ms);
        digitalWrite(relay_pin, LOW); // Turn OFF
        break;
    }
    }
    digitalWrite(relay_pin, LOW); // Turn OFF (failsafe)
}
delay(suspend_time);
}