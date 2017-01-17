/*
  Omar.cpp - Library for Simpling Ultasonic , Dc Motors and Servos through FLOW Shield .
  Created by Omar A.Okasha "Drmicrosoft", November 13, 2016.
  Released into the public domain.
*/

#include "Arduino.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/pgmspace.h>


#include "Video.h"


//1 

Video::Video(int pin, int pinx)
{
  _pin = pin;
  _pinx = pinx;
  
}

//2

long Video::uc()
{

 long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_pinx, INPUT);
  duration = pulseIn(_pinx, HIGH);

  // convert the time into a distance
  
  cm = microsecondsToCentimeters(duration);
  
  
  delay(100);
	return cm ;

}

//3

long Video:: microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//4

void Video::dc(int x,int y)
{
	if(x==0&&y==0)
	{
		digitalWrite(_pin,LOW);
		digitalWrite(_pinx,LOW);
	}
	
	if(x==1&&y==0)
	{
		digitalWrite(_pin,HIGH);
		digitalWrite(_pinx,LOW);
	}
	
	if(x==0&&y==1)
	{
		digitalWrite(_pin,LOW);
		digitalWrite(_pinx,HIGH);
	}
	
	if(x==1&&y==1)
	{
		digitalWrite(_pin,HIGH);
		digitalWrite(_pinx,HIGH);
	}
}


