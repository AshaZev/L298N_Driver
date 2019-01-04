/*
# L298N_Driver.cpp - Library for interfacing with the L298N's h bridge.
# Created by AshaZev, 2018/04/09.
# Last updated, 2019/01/04.
*/

#include "Arduino.h"
#include "L298N_Driver.h"

L298N_Driver::L298N_Driver(int in1, int in2, int en)
{
	input1 = in1;
	input2 = in2;
	enablePin = en;
	enabled = false;

	pinMode(input1, OUTPUT);
	pinMode(input2, OUTPUT);
	pinMode(enablePin, OUTPUT);

	neutral();
	setDuty(0);
}

void L298N_Driver::forward()
{
	enabled = true;
	digitalWrite(enablePin, LOW); //some budge
	digitalWrite(input1, HIGH);
	digitalWrite(input2, LOW);
}

void L298N_Driver::reverse()
{
	enabled = true;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, HIGH);
}

void L298N_Driver::brake()
{
	enabled = true;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, LOW);
}

void L298N_Driver::neutral()
{
	enabled = true;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, LOW);
}

void L298N_Driver::setDuty(int duty)
{
	analogWrite(enablePin, duty);	//default frequencey ~490Hz
}
