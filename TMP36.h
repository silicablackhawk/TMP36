//  TMP36.h
//  Created by Blaine Lewis on 1/11/16.

#ifndef TMP36_h
#define TMP36_h


//these lines import arduino specific code and call like pinMode and "INPUT"
#if (ARDUINO >= 100)
#include <Arduino.h>
#endif


/* This library supports temperature sensor TMP36
 the supporting code to get temperature
 and get Faherenheit temperature is here.
 
 this header file incudes necessary supporting functions
 that can be used publicly and privately
 */


class TMP36 {
    
public:
    
    //Constructor default for 5v board takes just input pin
    TMP36(int pin);
    //Constructor with specification for board voltage takes pin and board voltage;
    TMP36(int pin, bool fiveVolts);
    
    float
    getTemp(),
    getFah(),
    getFah(float cels);
    
    
private:
    const int
    tmpPin;
    int
    rawVal;
    float
    mVolts;
    bool
    isFive;
};


#endif /* TMP36_h */
