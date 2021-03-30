/*
 * rechner.cpp
 *
 *  Created on: 24.03.2021
 *      Author: pi
 */
#include <iostream>
using namespace std;

double readnum(){
	double num;
	cin>>num;
	while(cin.fail()){
		cout<<"Falsche Eingabe, bitte schreiben Sie das wieder"<<endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin>>num;
	}
	return num;
}

bool opisnotcorrect(char op){
	if (op=='+'){
		return false;}
	else if (op=='-'){
		return false;}
	else if (op=='*'){
		return false;}
	else if (op=='/'){
		return false;}
	else{
		return true;}
}

char readop(){
	char op;
	cin>>op;

	while(cin.fail()|| opisnotcorrect(op)){
		cout<<"Falsche Eingabe, bitte scrheiben Sie das wieder"<<endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin>>op;
		}
	return op;
}

double calculate(double n1, double n2, char op){
	if (op=='+'){
		return n1+n2;}
	else if (op=='-'){
		return n1-n2;}
	else if (op=='*'){
		return n1*n2;}
	else if (op=='/'){
		return n1/n2;}
	else {
		cout<<"Falsche Operator gescrhieben"<<endl; //unreachable code
		return 0.0;}

}

int rechner(){
	//main function
	cout<<"Schreiben Sie die erste Nummer: "<<endl;
	double num1=readnum();
	cout<<"Schreiben Sie den Operator: "<<endl;
	char oper=readop();
	cout<<"Schreiben Sie die zweite Nummer: "<<endl;
	double num2=readnum();
	while(num2==0 && oper=='/'){
		cout<<"Division unter 0 unmöglich, schreiben sie eine andere Nummer wieder"<<endl;
		num2=readnum();
	}
	double result=calculate(num1, num2, oper);
	cout<<"Ergebniss: "<<result<<endl;
	return 0;
}


