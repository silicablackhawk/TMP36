//
//  TMP36.cpp
//  
//
//  Created by Blaine Lewis on 1/11/16.
//
//

#include "TMP36.h"

//constructor with no board voltage specification defaulting to 5v
TMP36::TMP36(int pin):
tmpPin(pin) //asigns a constant value to the pin of sensor.
{
    isFive = 1;
    mVolts = 0;
    rawVal = 0;
}

//constructor with speificiation of board voltage.
TMP36::TMP36(int pin, bool fiveVolts):
    tmpPin(pin) //asigns a constant value to the pin of sensor.
{
    isFive = fiveVolts;
    mVolts = 0;
    rawVal = 0;
    
    pinMode(tmpPin, INPUT);
}

//GETS TEMP IN CELSIUS
float TMP36::getTemp()
{
    rawVal = analogRead(tmpPin);
    float temp = 0;
    
    if (isFive) {
        
        // 5V MATHS 10 bits give us 1024 possible levels of temperature.
        // each bit change will change 4.9 millivolts.
        // temp sensor TMP36 outputs 10mV for each degree celsius, calibrated at 750mV at 25C
        mVolts = 4.883 *rawVal;
    }
    else{
        // 3.3V MATHS millivolts
        // 3.3/1024 == 3.223mV per "tick"
        mVolts = 3.223 * rawVal;
    }
    
    // MATHS to convert millevolts to CELSIUS!!
    temp = (mVolts-500)/10;
    return temp;
}

//retruns Faherenheit given a celsius value.
float TMP36::getFah(float cels)
{
    float fah = (cels*1.8)+32;
    
    return fah;
}

//gets celsius value from sensor and returns faherenheit value
float TMP36::getFah()
{
    int cTemp = getTemp();
    
    float fah = (cTemp*1.8)+32;
    
    return fah;
}

