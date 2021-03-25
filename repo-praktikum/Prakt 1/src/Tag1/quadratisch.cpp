/*
 * quadratisch.cpp
 *
 *  Created on: 25.03.2021
 *      Author: pi
 */

#include <iostream>
#include <cmath>
using namespace std;

bool quadratisch(double a, double b, double c, double *x1, double *x2){
	//according to the formula (-b+-sqrt(b2-4ac))/2a
	double realp=pow(b,2)-4*a*c;
	if (realp<0){
		return false;
	}
	realp=sqrt(realp);
	*x1=(-b+realp)/(2*a);
	*x2=(-b-realp)/(2*a);
	return true;
}

int quad(){
	//main function
	double a,b,c;
	double r1,r2;
	double *x1=&r1;
	double *x2=&r2;
	cout<<"Write a: "<<endl;
	cin>>a;
	cout<<"Write b: "<<endl;
	cin>>b;
	cout<<"Write c: "<<endl;
	cin>>c;
	b=quadratisch(a,b,c, x1, x2);
	// b=quadratisch(a,b,c, &r1, &r2);
	if(b){
		cout<<"Real Solution: "<<endl;
		cout<<"x1: "<<*x1<<" ,x2: "<<*x2<<endl;
		// cout<<"x1: "<<r1<<" ,x2: "<<r2<<endl; //same result
	}
	else{
		cout<<"No real solution"<<endl;
	}
	return 0;
}



