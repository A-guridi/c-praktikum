/*
 * RobotControl.cpp
 *
 *  Created on: 06.04.2021
 *      Author: pi
 */

#include "RobotControl.h"
#include "ncurses.h"
#include <iostream>

using namespace std;

RobotControl* RobotControl::transferPointer;

RobotControl::RobotControl() {
	m_dRadius=0;
	m_dSpeed=0;
	m_bIs8=false;
	m_cInput=0;
	isActive=false;

	//for(int i=0;i<2;i++){
	//	RobotControl::wspeed[i]=0;
	//	}
	RobotControl::Interface=InterfaceSIM();
	transferPointer=this;
	RobotControl::Interface.Initialize(0.04, (*transferFunction));

	}

RobotControl::~RobotControl() {

}

void RobotControl::Communicate()
{
	std::cout<<"Soll ein (weiteres) Manoever gefahren werden? [y]/[n]"<<std::endl;
	std::cin>>m_cInput;
	if(m_cInput=='y'){
		isActive=true;
	}
	else{
		isActive=false;
		return;
	}
	PosEst.Reset();
	RobotControl::ManeuverSelect();
	if(m_bIs8){
		Man.CalcEight(m_dRadius,m_dSpeed,0.04);
	}
	else{
		Man.CalcCircle(m_dRadius,m_dSpeed,0.04);
	}
	initscr();
	nodelay(stdscr,TRUE);
	noecho();
	sigprocmask(SIG_UNBLOCK, & Interface.mask, nullptr);
	char chValue;
	printw("\n s: Start ; t: Stop ; p: Proceed ; q: End");
	while(chValue!='q'){
		chValue=getch();
		if(chValue!='q'&& chValue!=-1){
			printw("\n s: Start ; t: Stop ; p: Proceed ; q: End");
			clear();
			if(chValue=='s'){
				Man.Start();
				printw("\nStarting Maneuver");
			}
			else if(chValue=='t'){
				Man.Stop();
				printw("\nStopping Maneuver");
			}
			else if(chValue=='p'){
				Man.Proceed();
				printw("\nProceeding with Maneuver");
			}
		}
	}
	chValue='a';
	while(isspeed[0]!=0 && isspeed[1]!=0){
			// stopping robot
		Man.Stop();
		printw("Stopping robot");
		//shspeed[0]=0;
		//shspeed[1]=0;
	}
	printw("\nRobot stopped, ending keyboard control");
	clear();
	endwin();
	sigprocmask(SIG_BLOCK, & Interface.mask, nullptr);
}

void RobotControl::Run()
{
	RobotControl::Communicate();
}

bool RobotControl::ManeuverSelect()
{
	std::cout<<"select maneuver. type 'c' for circle, '8' for eight"<<std::endl;
	std::cin>>m_cInput;
	if(m_cInput=='c'||m_cInput=='C')
	{
		m_bIs8=false;
	}
	else if(m_cInput=='8')
	{
		m_bIs8=true;
	}
	else
	{
		return false;
	}
	std::cout<<"select radius."<<std::endl;
	std::cin>>m_dRadius;
	std::cout<<"select speed."<<std::endl;
	std::cin>>m_dSpeed;
	return true;
}

bool RobotControl::GetisActive()
{
	return isActive;
}
void RobotControl::transferFunction(){
	transferPointer->Step();
}

void RobotControl::Step()
{
	double ref=1500;
	double u[2];
	isspeed=RobotControl::Interface.GetInput();
	if(!Man.isRunning()){
		shspeed[0]=1500;
		shspeed[1]=1500;
	}
	else{

		PosEst.PredictPosition(isspeed[0], isspeed[1], 0.04);
		double* pos=PosEst.GetPostition();
		Man.CalcManeuverSpeed(pos[0], pos[1], pos[2]);
		sspeed=Man.GetManeuverSpeed();

		RobotControl::rcon.CalculateU(sspeed[0], isspeed[0]);
		RobotControl::lcon.CalculateU(sspeed[1], isspeed[1]);
		u[0]=rcon.GetU();
		u[1]=lcon.GetU();
		for(int i=0;i<2;i++){
		shspeed[i]=int(u[i]+ref);
		if(shspeed[i]<1000){
			shspeed[i]=1000;
		}
		else if(shspeed[i]>2000){
			shspeed[i]=2000;
		}
		}	//end for loop
	}
	Interface.SetOutputs(shspeed);
}

