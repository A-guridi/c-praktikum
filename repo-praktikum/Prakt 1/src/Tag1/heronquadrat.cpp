/*
 * heronquadrat.cpp
 *
 *  Created on: 24.03.2021
 *      Author: pi
 */

#include <iostream>
using namespace std;

double heron_ite(double num){
	double x=1.0;
	for (int i=0;i<10;i++){
		x=(x+num/x)/2;
	}
	return x;
}

int heron(){
	//main function
	cout<<"Input number: "<<endl;
	double input;
	cin>>input;
	double res=heron_ite(input);
	cout<<"Result: "<<res<<endl;
	return 0;
}


