/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 5
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include <iostream>
#include "lesson5.hpp"

using namespace std;

int main()
{
	// P1 /////////////////////////////////////////////////////////////////
	//
	cout << "Part 1:" << endl;
	Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << " " << p1.second() << endl;

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << " " << p2.second() << endl;

	// P2 /////////////////////////////////////////////////////////////////
	//
	cout << endl << "Part 2:" << endl;
	Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << " " << p3.second() << endl;

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << " " << p4.second() << endl;

	// P3 /////////////////////////////////////////////////////////////////
	//
	cout << endl << "Part 3:" << endl;
	StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << " " << svp.second() << endl;
	
	/* Part 4 - see ../../BlackJack
	*/

	cout << endl << "Done" << endl;
	return 0;
}
