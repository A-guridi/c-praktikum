/*
 * keyboard.h
 *
 *  Created on: 01.04.2021
 *      Author: pi
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_
#include "InterfaceSIM.h"
#include "Regler.h"

class KeyboardControl{
public:
	KeyboardControl();
	~KeyboardControl();
	void Step();
	void Communicate(double* speed);
	static KeyboardControl * transferPointer;
	static void transferFunction();
	double in=0.0;
	double* wspeed=&in;

private:

	double s=0.0;
	int r=1500;
	double *isspeed=&s;

	int* shspeed=&r;
	//double* inspeed;
	void adjustspeed(double *speed, char q);
	InterfaceSIM* myinter;
	PIDController rcon;	//right controller
	PIDController lcon; //left controller

};





#endif /* KEYBOARD_H_ */
