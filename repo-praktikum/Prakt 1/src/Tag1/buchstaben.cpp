/*
 * buchstaben.cpp
 *
 *  Created on: 24.03.2021
 *      Author: pi
 */

#include <iostream>
#include <string>
using namespace std;


string wordchange(string w){
	string ex;
	ex.append(1,w[0]);
	int l=w.size();
	int i;
	for(i=1;i<l-2;i=i+2){
		ex.append(1,w[i+1]);
		ex.append(1,w[i]);
	}
	if(i==l-2){
		ex.append(1,w[l-2]); //in case of uneven length of words
	}
	ex.append(1, w[l-1]);
	//cout<<"Changed word: "<<w<<endl;
	return ex;
}

string findandrep(string w, char a){
	int m;
	do{
		m=w.find(a);
		if(m==-1){
			break;
		}
		w.erase(m,1);
	}while(m!=-1); //end of search with npos
	return w;
}

string novocs(string w){
	string vocs="aeiou";
	for(int i=0; i<vocs.size();i++){
		w=findandrep(w, vocs[i]);
	}
	return w;
}

int buchstaben(){
	//main function
	cout<<"Write a word: "<<endl;
	string word, cword, nword;
	cin>>word;
	cword=wordchange(word);
	cout<<"Reordered word: "<<cword<<endl;
	nword=novocs(word);
	cout<<"No vocals word: "<<nword<<endl;
	return 0;
}

