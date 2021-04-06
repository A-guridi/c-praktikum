/*
 * RobotControl.h
 *
 *  Created on: 06.04.2021
 *      Author: pi
 */

#ifndef ROBOTCONTROL_H_
#define ROBOTCONTROL_H_

#include "posestimation.h"
#include "InterfaceSIM.h"
#include "Regler.h"
#include "maneuver.h"
#include "ncurses.h"

class RobotControl {


public:
	RobotControl();
	virtual ~RobotControl();
	static RobotControl * transferPointer;
	static void transferFunction();
	void Step();
	void Communicate();
	void Run();
	bool GetisActive();

private:
	double m_dRadius;
	double m_dSpeed;
	double s=0.0, o=0.0;
	int r=1500;
	double *isspeed=&s;
	double* sspeed=&o;
	int* shspeed=&r;
	bool m_bIs8;
	char m_cInput;
	bool isActive;
	bool ManeuverSelect();
	PosEstimation PosEst;
	InterfaceSIM Interface;
	Maneuver Man;
	PIDController rcon=PIDController(500.0, 100.0, 0.0, 0.04);;	//right controller
	PIDController lcon=PIDController(500.0, 100.0, 0.0, 0.04);; //left controller

};

#endif /* ROBOTCONTROL_H_ */
