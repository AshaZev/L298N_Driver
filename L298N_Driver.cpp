/*
# L298N_Driver.cpp - Library for interfacing with the L298N's h bridge.
# Created by AshaZev, 2018/04/09.
# Last updated, 2018/12/24.
*/

#include "Arduino.h"
#include "RC_Receiver.h"

L298N_Driver::L298N_Driver(int in1, int in2, int en)
{
	input1 = in1;
	input2 = in2;
	enablePin = en;
	enabled = FALSE;

	pinMode(input1, OUTPUT);
	pinMode(input2, OUTPUT);
	pinMode(enablePin, OUTPUT);

	neutral();
	setDuty(0.0f);
}

void L298N_Driver::forward()
{
	enabled = TRUE;
	digitalWrite(enablePin, LOW); //some budge
	digitalWrite(input1, HIGH);
	digitalWrite(input2, LOW);
}

void L298N_Driver::reverse()
{
	enabled = TRUE;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, HIGH);
}

void L298N_Driver::brake()
{
	enabled = TRUE;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, LOW);
}

void L298N_Driver::neutral()
{
	enabled = FALSE;
	digitalWrite(enablePin, LOW);
	digitalWrite(input1, LOW);
	digitalWrite(input2, LOW);
}

void L298N_Driver::setDuty(float duty)
{
	dutyRate = duty;  //change duty timer
	if (dutyRate < 0.0f)
	{
		dutyRate = 0.0f;
	}
	else if (dutyRate > 1.0f)
	{
		dutyRate = 1.0f;
	}

	analogWrite(enablePin, dutyRate);	//default frequencey ~490Hz
}
