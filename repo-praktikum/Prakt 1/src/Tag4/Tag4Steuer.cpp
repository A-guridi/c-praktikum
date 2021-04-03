//============================================================================
// Name        : Tag4Steuer.cpp
// Author      : Arturo
// Version     :
// Copyright   : Your copyright notice
// Description : Project robot
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "keyboard.h"
#include "Regler.h"
using namespace std;

int pidchecker() {
	//to check to main
	double Kp=1000;
	double Ki=10;
	double Kd=0.1;
	double Ta=0.5;
	PIDController mycontrol(Kp, Ki, Kd, Ta);
	//file
	fstream file;
	double w=0,y=0, u;
	file.open("PIDControllerInput.txt", ios::in);
	if(file.is_open()){
		cout<<"File opened"<<endl;
	for(int i=0;i<10;i++){
		file>>w;
		file>>y;
		cout<<w<<" "<<y<<" ";
		mycontrol.CalculateU(w,y);
		u=mycontrol.GetU();
		cout<<", U: "<<u<<endl;

	} }
	file.close();
	// checked fine
	return 0;
}
int main(){
	KeyboardControl *mykey=new KeyboardControl();
	mykey->Communicate(mykey->wspeed);
	return 0;
}
