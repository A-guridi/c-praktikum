//============================================================================
// Name        : Tag5.cpp
// Author      : Arturo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "RobotControl.h"
#include "posestimation.h"
#include "maneuver.h"
using namespace std;

int posechecker() {
	//function to check the pos estimation class
	PosEstimation mypose=PosEstimation();
	fstream file;
	double ls, rs, ts;
	double *u;
	file.open("PosEstimationInput.txt", ios::in);
	if(file.is_open()){
			cout<<"File opened"<<endl;
		for(int i=0;i<10;i++){
			file>>rs;
			file>>ls;
			file>>ts;
			mypose.PredictPosition(rs, ls, ts);
			u=mypose.GetPostition();
			cout<<"U: ";
			for (int j=0;j<3;j++){
				cout<<u[j]<<" ";
			}
			cout<<endl;
		} }
		file.close();
		// checked fine
		return 0;
}

int mancomparer(void)
{
	//function to check the maneuver circle and eight
	//Streams zum Einlesen der Werte erzeugen
	ifstream InputFileEight;
	ifstream InputFileCircle;
	ifstream VglFileCircle;
	ifstream VglFileEight;

	Maneuver myman=Maneuver();
	string s="mycircle.txt";
	myman.CalcCircle(2.0, 0.3, 0.04);
	myman.LogList(s);
	s="myeight.txt";
	myman.CalcEight(5.0, 1.0, 10.0);
	myman.LogList(s);

	//Vergleichsdateien oeffnen
	//VglFileCircle.open("ListCircleVgl.txt", ios::in);
	VglFileCircle.open("mycircle.txt", ios::in);
	if(VglFileCircle.fail())
	{
		cout << "'ListCircleVgl.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}
	//VglFileEight.open("ListEightVgl.txt", ios::in);
	VglFileEight.open("myeight.txt", ios::in);
	if(VglFileEight.fail())
	{
		cout << "'ListEightVgl.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}

	//Inputdatein oeffnen
	InputFileCircle.open("LogFileCircle.txt", ios::in);
	if(InputFileCircle.fail())
	{
		cout << "'LogFileCircle.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}
	InputFileEight.open("LogFileEight.txt", ios::in);
	if(InputFileEight.fail())
	{
		cout << "'LogFileEight.txt' konnte nicht geoeffnet werden!" << endl;
		return -1;
	}

	//Variablen fuer Inputwerte
	double dInput = 0.0;

	//Variablen fuer Vergleichswerte
	double dVgl = 0.0;

	//Varibale zur Uberpruefung, ob Input- und Vergleichsdatei uebereinstimmen
	bool bCorrect = true;

	//Kreis ueberpruefen
	while(!InputFileCircle.eof())
	{
		//Werte aus Inputdatei einlesen
		InputFileCircle >> dInput;

		//Wert aus Vergleichsdatei einlesen
		VglFileCircle >> dVgl;

		if(dInput != dVgl)	bCorrect = false;
	}

	//Ausgabe, ob die Kreis-Inputdatein korrekt ist
	if(bCorrect)
	{
		cout << "Die Datei 'LogFileCircle.txt' wurde korrekt erstellt" << endl;
	}
	else
	{
		cout << "Die Datei 'LogFileCircle.txt' wurde nicht korrekt erstellt" << endl;
	}

	//Acht ueberpruefen
	while(!InputFileEight.eof())
	{
		//Werte aus Inputdatei einlesen
		InputFileEight >> dInput;

		//Wert aus Vergleichsdatei einlesen
		VglFileEight >> dVgl;

		if(dInput != dVgl)	bCorrect = false;
	}

	//Ausgabe, ob die Acht-Inputdatein korrekt ist
	if(bCorrect)
	{
		cout << "Die Datei 'LogFileEight.txt' wurde korrekt erstellt" << endl;
	}
	else
	{
		cout << "Die Datei 'LogFileEight.txt' wurde nicht korrekt erstellt" << endl;
	}

	//Dateien schliessen
	InputFileCircle.close();
	InputFileEight.close();
	VglFileCircle.close();
	VglFileEight.close();

	return 0;
}

int main(){
	RobotControl control=RobotControl();
	do{

	control.Run();

	}while(control.GetisActive());
	return 0;
}
