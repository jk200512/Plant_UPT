#include <Arduino.h>
#include <time.h>

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

int WAITING_TIME_ms = 3000;             // aeg, mil pump töötab enne välja lülitamist (3 sec)
unsigned long SUSPEND_TIME_ms = 900000; // aeg, kui kaua arduino ootab enne uut tsükklit (15 min)
unsigned long MAX_DELTA_TIME = 4000;    // max aeg, mil pump võib töötada, kahe aja delta
int LEVEL_DRY = 340;                    // mulla niiskuse level cap. sensoritele 
int LEVEL_WET = 200;                    // vee märguse nivoo torus oleva andurile

void loop()
{
  int sensor_1_val = analogRead(1); // in soil
  int sensor_2_val = analogRead(2); // in soil

  //Serial.print("Niiskus mullas: "); // Prindib lause
  //Serial.print(sensor_1_val);       // Prindib A1 value
  //Serial.print(" ; ");              // Prindib tühiku ja kooloni
  //Serial.println(sensor_2_val);     // Prindib A2 value

  if ((sensor_1_val > LEVEL_DRY) and (sensor_2_val > LEVEL_DRY)) // Kui A1 ja A2 valued on suuremad kui 340, siis täida alumist osa
  {
    digitalWrite(8, HIGH);                       // Turn ON
    unsigned long time_0 = millis();             // Esimene aja küsimine (Esimene aeg)
    while ((millis() - time_0) < MAX_DELTA_TIME) // While loop töötab kuni praeguse aja ja esimese aja vahe on väiksem kui 15000
    {
      int sensor_0_val = analogRead(0); // attached to water tube
      if (sensor_0_val >= LEVEL_WET)    // Kui A0 on võrdne või suurem kui 200, siis täida alumist osa
      {
        delay(WAITING_TIME_ms); // Oota 3 sec
        digitalWrite(8, LOW);   // Turn OFF
        break;                  // Väljub "While" tsüklist
      }
      //Serial.println(sensor_0_val); //(troubleshooting)
    }
    digitalWrite(8, LOW); // Turn OFF (failsafe)
  }
  delay(SUSPEND_TIME_ms); // Oota 15 min
}