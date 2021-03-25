/*
 * referenzen.cpp
 *
 *  Created on: 25.03.2021
 *      Author: pi
 */
#include <iostream>
using namespace std;

void swap(int &p1, int &p2){
	int aux=p1;
	p1=p2;
	p2=aux;
}

int swaper(){
	//main function
	int v1,v2;
	cout<<"Write first value: "<<endl;
	cin>>v1;
	cout<<"Write second value: "<<endl;
	cin>>v2;
	swap(v1,v2);
	cout<<"First value: "<<v1<<" ,Second value: "<<v2<<endl;
	return 0;

}


