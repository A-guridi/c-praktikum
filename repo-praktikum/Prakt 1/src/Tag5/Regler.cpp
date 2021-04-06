/*
 * Regler.cpp
 *
 *  Created on: 02.04.2021
 *      Author: pi
 */
#include "Regler.h"


PIDController::PIDController(){
	PIDController::dKd=0;
	PIDController::dKi=0;
	PIDController::dKp=0;
	PIDController::dTa=0;
	PIDController::deold=0;
	PIDController::dEsum=0;
	PIDController::dU=0;
}

PIDController::PIDController(double Kp, double Ki, double Kd, double Ta){
	PIDController::dKd=Kd;
	PIDController::dKi=Ki;
	PIDController::dKp=Kp;
	PIDController::dTa=Ta;
	PIDController::deold=0;
	PIDController::dEsum=0;
	PIDController::dU=0;
}

PIDController::~PIDController(){
	//deconstructor
}

void PIDController::CalculateU(double w, double y){
	double e=w-y;
	PIDController::dEsum=PIDController::dEsum+e;
	PIDController::dU=PIDController::dKp*e+PIDController::dKi*PIDController::dTa*PIDController::dEsum+
			PIDController::dKd*(e-PIDController::deold)/PIDController::dTa;
	PIDController::deold=e;


}

double PIDController::GetU(){
	return PIDController::dU;
}


