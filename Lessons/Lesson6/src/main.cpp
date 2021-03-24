/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 6
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include <iostream>
#include "lesson6.hpp"

using namespace std;

// Part 2
ostream& endll(ostream& os){
	os << endl << endl;
	return (os);
}

int main()
{
	// P1 /////////////////////////////////////////////////////////////////
	//
	cout << "Part 1:" << endl;
	string prompt = "Enter an integer: ";
	int ivalue = 0;

	while (true){
		cout << prompt;
		cin >> ivalue;
		if (!cin.good()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else{
			break;
		}
	}
	cout << "Valid integer: " << ivalue << endl;

	// P2 /////////////////////////////////////////////////////////////////
	//
	cout << "Part 2:" << endl;
	cout << "part 2 done (see below)" << endll;
	cout << "(yes)" << endl;

	// P3/4/5 /////////////////////////////////////////////////////////////////
	//
	cout << "Parts 3, 4 and 5 - see ../../BlackJack:" << endl;
	
	cout << endl << "Done" << endl;
	return 0;
}
