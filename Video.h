/*
  Omar.h - Library for Simpling Ultasonic , Dc Motors and Servos through FLOW Shield .
  Created by Omar A.Okasha "Drmicrosoft", November 13, 2016.
  Released into the public domain.
*/

#ifndef Video_h
#define Video_h


#include "Arduino.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/pgmspace.h>

   

class Video
{
  public:
  
    Video(int pin,int pinx);
    long uc();
    void dc(int x,int y);
    long microsecondsToCentimeters(long microseconds);
 
    
    
    
  private:
    int _pin;
    int _pinx;
    
};

#endif

