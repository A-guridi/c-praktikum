/*
 * Regler.h
 *
 *  Created on: 02.04.2021
 *      Author: pi
 */

#ifndef REGLER_H_
#define REGLER_H_

class PIDController{
private:
	double dKi;
	double dKp;
	double dKd;
	double dTa;
	double dEsum;
	double deold;
	double dU;
public:
	PIDController();
	PIDController(double Kp, double Ki, double Kd, double Ta);
	~PIDController();
	void CalculateU(double w, double y);
	double GetU();
};




#endif /* REGLER_H_ */
