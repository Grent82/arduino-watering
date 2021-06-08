#ifndef WATER_PUMP_H
#define WATER_PUMP_H

class WaterPump
{

    int pumpPin;      // the number of the LED pin

public:
    WaterPump();  
    void Init(int pin);  
    void Update(int state);
};

#endif