/*
 * maneuver.cpp
 *
 *  Created on: 04.04.2021
 *      Author: pi
 */

#include <cmath>
#include "maneuver.h"

using namespace std;

Maneuver::Maneuver(){

	CoordList.clear();

	bIsRunning=false;
	adWishSpeed[0]=0;
	adWishSpeed[1]=0;
	dMaxSpeed=0.5;
	dPosDifference=0;
}

Maneuver::~Maneuver(){
	//destructor
}

void Maneuver::CalcCircle(double dRadius, double dSpeed, double dTimestep){
	Coord mycords;
	CoordList.clear(); //empties the list
	double v=dSpeed;
	double R=dRadius;
	double T=dTimestep;
	mycords.dV=v;
	for(int counter = 1; counter<(int)((2*M_PI)/((v/R)*T)); counter++){
		mycords.dX=R*sin(counter*(v/R)*T);
		mycords.dY=R*(1-cos(counter*(v/R)*T));
		CoordList.push_back(mycords);
	}

}

void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep){
	Coord mycords;
	CoordList.clear();	//clear list
	double v=dSpeed;
	double R=dRadius;
	double T=dTimestep;
	mycords.dV=v;
	//first circle
	for(int counter = 1; counter<(int)((2*M_PI)/((v/R)*T)); counter++){
			mycords.dX=R*sin(counter*(v/R)*T);
			mycords.dY=R*(1-cos(counter*(v/R)*T));
			CoordList.push_back(mycords);
		}
	//second circle
	for(int counter = 1; counter<(int)((2*M_PI)/((v/R)*T)); counter++){
			mycords.dX=R*sin(counter*(v/R)*T);
			mycords.dY=-R*(1-cos(counter*(v/R)*T));
			CoordList.push_back(mycords);
		}
}

void Maneuver::LogList(string sDatei){
	fstream file;
	file.open(sDatei, ios::out | ios::trunc ); //write mode
	if(file.is_open()){
	for(iter=CoordList.begin(); iter!=CoordList.end();iter++){
		file<<iter->dX<<" "<<iter->dY<<endl;
	}
	file.close();
	}
	else{
		cout<<"Error while opening file"<<endl;
	}
}

bool Maneuver::isRunning(){
	return bIsRunning;
}

void Maneuver::Start(){
	iter=CoordList.begin();
	bIsRunning=true;
}

void Maneuver::Stop(){
	bIsRunning=false;
}

void Maneuver::Proceed(){
	bIsRunning=true;
}

void Maneuver::CalcManeuverSpeed(double x, double y, double w){
	double xsoll=iter->dX;
	double ysoll=iter->dY;
	dPosDifference=sqrt((xsoll-x)*(xsoll-x)+(ysoll-y)*(ysoll-y))
	if (dPosDifference>0.02){
		if(iter==CoordList.end()){
			adWishSpeed[0]=0;
			adWishSpeed[1]=0;
			Maneuver::Stop();
			return;
		}
		//else
		double angledif=atan2(ysoll-y, xsoll-x)-w; //difference between should angle and real angle
		//limit angle to [-pi, pi]
		if (angledif>M_PI){
			angledif-=2*M_PI;
		}
		else if(angledif<= - M_PI){
			angledif+=2*M_PI;
		}
		// create the rotation part
		double dRot=angledif*2;
		if(dRot>0.5){
			dRot=0.5;
		}
		else if(dRot<-0.5){
			dRot=-0.5;
		}
		// translation part
		double dTra=iter->dV;
		if(dTra*dRot>0){
			if(dTra+dRot>dMaxSpeed){
				dTra=dMaxSpeed-dRot;
			}
			else if(dTra+dRot< -dMaxSpeed){
				dTra=-dMaxSpeed-dRot;
			}
		}
		else{	//dTra*dRot<0
			if(dTra-dRot>dMaxSpeed){
				dTra=dMaxSpeed+dRot;
			}
			else if(dTra-dRot< -dMaxSpeed){
				dTra= -dMaxSpeed+dRot;
			}
		}
		//addition of the two parts
		adWishSpeed[0]=dTra+dRot;
		adWishSpeed[1]=dTra-dRot;
	}
	else{	//the robot is in the position it should be
		iter++;
	}
}

double* Maneuver::GetManeuverSpeed(){
	return adWishSpeed;
}

