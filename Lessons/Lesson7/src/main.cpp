/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 7
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include <iostream>
#include "lesson7.hpp"

using namespace std;

int main()
{
	// P1 /////////////////////////////////////////////////////////////////
	//
	cout << "Part 1:" << endl;
	shared_ptr<Date> today(new Date(2021,03,27));
	shared_ptr<Date> date;

	cout << "date inside today:" << endl;
	cout << '\t' << "today" << '\t' << today << endl;
	cout << '\t' << "date " << '\t' << date << endl;
	cout << '\t' << "today->year():  " << today->year() << endl; // // tabs is not so precise
	cout << '\t' << "today->month(): " << today->month() << endl; 
	cout << '\t' << "today->day():   " << today->day() << endl; 
	cout << '\t' << "throu operator: " << *today << endl; 

	date.swap(today);
	cout << "date/today swapped:" << endl;
	cout << '\t' << "today" << '\t' << today << endl;
	cout << '\t' << "date " << '\t' << date << endl;

	today.reset();
	date.reset();
	cout << "date&today reseted:" << endl;
	cout << '\t' << "today" << '\t' << today << endl;
	cout << '\t' << "date " << '\t' << date << endl;

	// P2 /////////////////////////////////////////////////////////////////
	//
	cout << endl << "Part 2:" << endl;
	shared_ptr<Date> date1(new Date(2021,3,27));
	shared_ptr<Date> date2(new Date(2020,12,31));
	Date greater_date = max_date(date1, date2);
	cout << "date1 is:   " << *date1 << endl; // tabs is not so precise
	cout << "date2 is:   " << *date2 << endl; 
	cout << "greater is: " << greater_date << endl; 
	swap_dates(date1, date2);
	cout << "date1/date2 swapped:" << endl;
	cout << '\t' << "date1 is: " << *date1 << endl;
	cout << '\t' << "date2 is: " << *date2 << endl;

	// P3/4/5 /////////////////////////////////////////////////////////////////
	//
	cout << endl << "Parts 3, 4 and 5 - see ../../BlackJack:" << endl;
	
	cout << endl << "Done" << endl;
	return 0;
}
