/*
 * speicher.cpp
 *
 *  Created on: 25.03.2021
 *      Author: pi
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

int stacker(){
	//main function
	srand(time(nullptr));
	int l=100000;
	int *mystack=new int[l];
	//int mystack[l]; //this one outputs memory problems (corruption)
	int i;
	int count=0;
	for(i=0;i<l;i++){
		mystack[i]=rand()%100;
	}
	for(i=0;i<l;i++){
		if(mystack[i]%13==0){
			count++;
		}
	}
	std::cout<<count<<" elements from stack multiple of 13"<<std::endl;
	delete[] mystack;
	std::cout<<"Stack deleted"<<std::endl;
	return 0;
}


