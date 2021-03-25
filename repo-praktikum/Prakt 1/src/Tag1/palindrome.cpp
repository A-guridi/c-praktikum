/*
 * palindrome.cpp
 *
 *  Created on: 24.03.2021
 *      Author: pi
 */

#include <iostream>
#include <string>
using namespace std;

string convlow(string s){
	for(int i=0; i<s.size();i++){
		s[i]=tolower(s[i]); //convert to lowercase
	}
	return s;
}

bool ispalindrome(string w){
	int j=0;
	int len=w.size();
	if (len%2==0){
		return false;
	}
	for(int i= len-1; i >= len/2-1; i--){
		if(w[i]!=w[j]){
			return false; }
		j++;
		}
	return true;
}
int palind(){
	//main function
	string inword;
	cout<<"Write the input word"<<endl;
	cin>>inword;
	inword=convlow(inword);
	bool n=ispalindrome(inword);
	if (n){
		cout<<"Word is a palindrom"<<endl;
	}
	else{
		cout<<"Word is not a palindrom"<<endl;
	}
	return 0;
}



