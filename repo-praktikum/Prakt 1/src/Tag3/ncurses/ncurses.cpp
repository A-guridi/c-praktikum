
#include <iostream>
#include <list>
#include "ncurses.h"
using namespace std;


int main() {
	list<char> mylist;
	char chValue = 'a';
	initscr();
	nodelay(stdscr,TRUE);
	noecho();
	while(chValue!='q'){
		chValue=getch();
		if(chValue!='q'&& chValue!=-1){
			clear();
			mylist.push_back(chValue);
			printw("Eingabe ist: %c", chValue); // Ausgabe: char
		}
	}
	clear();
	endwin();
	list<char>::iterator iter;
	cout<<"List: ";
	for (iter=mylist.begin();iter!=mylist.end();iter++){
		cout<<*(iter)<<"; ";
	}
	return 0;
}
