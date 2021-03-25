/*
 * mazazahlen.cpp
 *
 *  Created on: 24.03.2021
 *      Author: pi
 */
#include <iostream>
using namespace std;

int mayconverter(int decnum){
	int base=20;
	int div=decnum;
	int mod=0;
	int result=0;
	int cont=1;
	do{
		mod=div%base;
		div=div/base;
		result=result+cont*mod;
		cont=cont*10;
	}while(div!=0);
	return result;
}

int convertmay(){
	//main function
	int decnum;
	cout<<"Write the number to convert"<<endl;
	cin>>decnum;
	int convnum=mayconverter(decnum);
	cout<<"Result: "<<convnum<<endl;
	return 0;
}



