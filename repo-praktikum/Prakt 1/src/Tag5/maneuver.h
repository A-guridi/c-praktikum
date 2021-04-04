/*
 * maneuver.h
 *
 *  Created on: 04.04.2021
 *      Author: pi
 */


#ifndef MANEUVER_H_
#define MANEUVER_H_

#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

class Maneuver{
private:
	struct Coord{
		double dX;
		double dY;
		double dV;
	};
	list<Coord> CoordList;
	list<Coord>::iterator iter;
	bool bIsRunning;
	double adWishSpeed[2];
	double dMaxSpeed;
	double dPosDifference;

public:
	Maneuver();
	~Maneuver();
	void CalcCircle(double dRadius, double dSpeed, double dTimestep);
	void CalcEight(double dRadius, double dSpeed, double dTimestep);
	void LogList(string sDatei);
	bool isRunning();
	void Start();
	void Stop();
	void Proceed();
	void CalcManeuverSpeed(double X, double Y, double W);
	double* GetManeuverSpeed();


};



#endif /* MANEUVER_H_ */
