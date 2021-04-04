/*
 * posestimation.cpp
 *
 *  Created on: 04.04.2021
 *      Author: pi
 */
#include "posestimation.h"
#include <cmath>

PosEstimation::PosEstimation(){
	for(int i=0;i<3;i++){
		x[i]=0;
	}
	dVelAverage=0;
}

PosEstimation::~PosEstimation(){

}

void PosEstimation::Reset(){
	for(int i=0;i<3;i++){
			x[i]=0;
		}
		dVelAverage=0;
}

void PosEstimation::PredictPosition(double dSpeedR, double dSpeedL, double dTimestep){
	x[0]=x[0]+dVelAverage*dTimestep*cos(x[2]);	//calculate x and y with the previous values
	x[1]=x[1]+dVelAverage*dTimestep*sin(x[2]);
	// new values
	//angle
	x[2]=x[2]+dTimestep*(dSpeedR-dSpeedL)/0.23;
	x[2]=fmod(x[2], 2* M_PI);
	if(x[2]>M_PI){
		x[2]-=2*M_PI;
	}
	else if(x[2]<=-M_PI){
		x[2]+=2*M_PI;
	}
	//speed
	dVelAverage=(dSpeedR+dSpeedL)/2;

}

double* PosEstimation::GetPostition(){
	return x;
}

