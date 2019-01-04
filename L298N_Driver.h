/*
# H_Bridge.h - Library for interfacing with the L298N's h bridge.
# Created by AshaZev, 2018/04/09.
# Last updated, 2019/01/04.
*/

#ifndef L298N_Driver_h
#define L298N_Driver_h

#include "Arduino.h"

class L298N_Driver
{
	private:
	int input1;
	int input2;
	int enablePin;
	bool enabled;
	float dutyRate;

	public:
	L298N_Driver(int in1, int in2, int en);
	void forward();
	void reverse();
	void brake();	//posible duty modulation
	void neutral();
	void setDuty(int duty);	//accepts vlues from 0.0f to 1.0f

};

#endif
