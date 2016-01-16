//  TMP36.cpp
//  Created by Blaine Lewis on 1/11/16.

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
    delay(1);   // artificial delay to smooth ADC converter noise if switching from a different input.
    rawVal = analogRead(tmpPin);     //I suppose this could be elsewhere

    
    float temp = 0;
    
    //converts rawVal to millivolts
    if (isFive) {
        // 5V MATHS
        //(5000mV/1024) gets "tick level" for each bit of feedback from ADC based on 10 bit ADC
        // multiply that by the rawVal to calculate millivolts
        mVolts = (5000.0/1024.0)*rawVal;
    }
    else{
        // 3.3V MATHS
        //(3300mV/1024) gets "tick level" for each bit of feedback from ADC based on 10 bit ADC
        // multiply that by the rawVal to calculate millivolts
        mVolts = (3300.0/1024.0)*rawVal;
    }
    
    // MATHS to convert millivolts to CELSIUS!!
    //temp sensor TMP36 outputs 10mV for each degree celsius, calibrated at 750mV at 25C
    temp = (mVolts-500)/10;
    
    return temp;
}

//retruns Fahrenheit given a celsius value.
float TMP36::getFah(float cels)
{
    float fah = (cels * 9.0 / 5.0)+32;
    
    return fah;
}

//gets celsius value from sensor and returns fahrenheit value
float TMP36::getFah()
{
    int cTemp = getTemp();
    
    float fah = (cTemp*1.8)+32;
    
    return fah;
}

