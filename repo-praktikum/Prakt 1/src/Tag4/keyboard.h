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
	void Communicate();
	static KeyboardControl * transferPointer;
	static void transferFunction();
	double in=0.0;
	double wspeed[2];

private:
	double s=0.0;
	int r=1500;
	double *isspeed=&s;
	int* shspeed=&r;
	//double* inspeed;
	void adjustspeed(double *speed, char q);
	InterfaceSIM myinter;
	PIDController rcon=PIDController(500.0, 185.0, 0.0, 0.04);;	//right controller
	PIDController lcon=PIDController(500.0, 185.0, 0.0, 0.04);; //left controller

};





#endif /* KEYBOARD_H_ */
