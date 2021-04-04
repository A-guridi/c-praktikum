/*
 * posestimation.h
 *
 *  Created on: 04.04.2021
 *      Author: pi
 */

#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_

class PosEstimation{
private:
	double x[3];
	double dVelAverage;

public:
	PosEstimation();
	~PosEstimation();
	void Reset();
	void PredictPosition(double dSpeedR, double dSpeedL, double dTimestep);
	double* GetPostition();

};



#endif /* POSESTIMATION_H_ */
