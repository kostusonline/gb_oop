/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 4
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "lesson4.hpp"

using namespace std;

int _rand(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
	return num;
}

void _print_vector(vector<int> v){
	const int cc = v.size();
	for (int i = 0; i < cc; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(nullptr));

	// P1 /////////////////////////////////////////////////////////////////
	cout << "Part 1:" << endl;
	const int alen = 10;
	ArrayInt a(alen);
	for (int i = 0; i < alen; ++i){
		a[i] = _rand(0, 20);
	}
	cout << "initial: ";
	a.print();
	
	a.sort();
	cout << "sorted: "; a.print();

	a.push_back(222);
	a.push_back(333);
	cout << "push_back twice: "; a.print();

	a.pop_front();
	cout << "pop_front: "; a.print();

	cout << "pop_back: "; a.pop_back();
	a.print();

	a.erase();

	// P2 /////////////////////////////////////////////////////////////////
	cout << endl << "Part 2:" << endl;
	vector<int> v = { 1,1,1,2,56,23,1,2,7,23 };
	cout << "initial vector: ";
	_print_vector(v);

	sort(v.begin(), v.end());
	cout << "sorted vector: ";
	_print_vector(v);

	vector<int>::iterator it;
	it = unique(v.begin(), v.end());  
	v.resize(distance(v.begin(),it));  
	cout << v.size() << " group(s) in vector: ";
	_print_vector(v);

	/* Part 3 - see ../../BlackJack
	*/

	cout << endl << "Done" << endl;
	return 0;
}
