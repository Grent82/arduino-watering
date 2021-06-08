#include "config.h"
#include "pump.h"

WaterPump pump;

int _ledState;             		// ledState used to set the LED
unsigned long _previousMillis;  	// will store last time LED was updated

long _onTime;     // milliseconds of on-time
long _offTime;    // milliseconds of off-time

void setup() {
  _ledState = LOW;
  _previousMillis = 0;

  _onTime = 2000;
  _offTime = 2000;

  Serial.begin(BAUD_DEFAULT);

  pump.Init(2);
  pump.Update(LOW);

  Serial.println("Automatic irrigation system");
}

void loop() {
  unsigned long currentMillis = millis();

  if ((_ledState == HIGH) && (currentMillis - _previousMillis >= _onTime))
  {
    Serial.println("PUMP OFF");
    _ledState = LOW;  // Turn it off
    _previousMillis = currentMillis;  // Remember the time
    pump.Update(_ledState);  // Update the actual LED
  }
  else if ((_ledState == LOW) && (currentMillis - _previousMillis >= _offTime))
  {
    Serial.println("PUMP ON");
    _ledState = HIGH;  // turn it on
    _previousMillis = currentMillis;   // Remember the time
    pump.Update(_ledState);	  // Update the actual LED
  }
}
