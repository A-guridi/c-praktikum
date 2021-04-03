/*
 * keyboard.cpp
 *
 *  Created on: 01.04.2021
 *      Author: pi
 */

#include "keyboard.h"
#include "ncurses.h"
#include <iostream>
using namespace std;

KeyboardControl* KeyboardControl::transferPointer;

KeyboardControl::KeyboardControl(){
	KeyboardControl::rcon=PIDController(500.0, 185.0, 0.0, 0.04);
	KeyboardControl::lcon=PIDController(500.0, 185.0, 0.0, 0.04);
	for(int i=0;i<2;i++){
	//KeyboardControl::inspeed[i]=0.0;

	//KeyboardControl::wspeed=&in;
	//KeyboardControl::shspeed=&r;
	}
	KeyboardControl::myinter=new InterfaceSIM();
	KeyboardControl::myinter->Initialize(0.04, & transferPointer->transferFunction); //is this transferFunction ??
	transferPointer=this;
}

KeyboardControl::~KeyboardControl(){
//deconstructor
}
//index 0: right motor
//index 1: left motor

void KeyboardControl::adjustspeed(double *speed, char q){
	switch(q){
	case 'w':
		speed[0]+=0.01;
		speed[1]+=0.01;
		break;
	case 's':
		speed[0]-=0.01;
		speed[1]-=0.01;
		break;
	case 'a':		//go left
		speed[0]+=0.005;
		speed[1]-=0.005;
		break;
	case 'd':
		speed[0]-=0.005;	//go right
		speed[1]+=0.005;
		break;
	case 'b':
		speed[0]=0;
		speed[1]=0;
		break;
	case 'q':
		//unreachable code
		printw("Robot being stopped ");
		break;
	default:
		printw("\nNot recognized %c command, please write (w,a,s,d,b) or q for exit \n", q);
		break;
	}
	//check if max/min speed is reached

}

void KeyboardControl::Communicate(double* speed){
	sigprocmask(SIG_UNBLOCK, & KeyboardControl::myinter->mask, nullptr);
	initscr();
	nodelay(stdscr,TRUE);
	noecho();
	char chValue;
	while(chValue!='q'){
		chValue=getch();
		if(chValue!='q'&& chValue!=-1){
			clear();
			KeyboardControl::adjustspeed(speed, chValue);
			if(speed[0]>0.5){
				speed[0]=0.5;
			}
			if(speed[1]>0.5){
				speed[1]=0.5;
			}
			if(speed[0]<-0.5){
				speed[0]=-0.5;
			}
			if(speed[1]<-0.5){
				speed[1]=-0.5;
			}
			printw("%c pressed", chValue); // Ausgabe: char
			printw("\nNew speed: (left) %f (right) %f", speed[0], speed[1]);
			sigprocmask(SIG_BLOCK, & KeyboardControl::myinter->mask, nullptr);
		}
		else{
		sigprocmask(SIG_BLOCK, & KeyboardControl::myinter->mask, nullptr);}
	}

	while(speed[0]!=0 && speed[1]!=0){
		printw("\nStopping robot");
		KeyboardControl::adjustspeed(speed, 'b');
	}
	printw("\nRobot stopped, ending keyboard control");
	clear();
	endwin();
	//sigprocmask(SIG_BLOCK, & KeyboardControl::myinter->mask, nullptr);
}

void KeyboardControl::Step(){
	isspeed=KeyboardControl::myinter->GetInput(); 	//is speed
	double u[2];			// output signal
	double ref=1500;	//null value of the signal
	//double* wspeed;
	KeyboardControl::Communicate(wspeed);
	KeyboardControl::rcon.CalculateU(wspeed[0], isspeed[0]);
	KeyboardControl::lcon.CalculateU(wspeed[1], isspeed[1]);
	u[0]=KeyboardControl::rcon.GetU();
	u[1]=KeyboardControl::lcon.GetU();
	for(int i=0;i<2;i++){
	// KeyboardControl::shspeed[i]=int(1000*stspeed[i]+ref); //old method for speed
	KeyboardControl::shspeed[i]=int(u[i]+ref);
	if(KeyboardControl::shspeed[i]<1000){
		KeyboardControl::shspeed[i]=1000;
	}
	else if(KeyboardControl::shspeed[i]>2000){
		KeyboardControl::shspeed[i]=2000;
	}
	}	//end for loop
	cout<<"Sys: "<<shspeed[0]<<"; "<<shspeed[1]<<endl;
	printw("\nSpeeds: %f %f", KeyboardControl::shspeed[0], KeyboardControl::shspeed[1]);
	KeyboardControl::myinter->SetOutputs(KeyboardControl::shspeed);
}

void KeyboardControl::transferFunction(){
	 transferPointer->Step();
}


