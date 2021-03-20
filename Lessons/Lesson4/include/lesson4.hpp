#ifndef _LESSON4_HPP_
#define _LESSON4_HPP_

#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt();
    ArrayInt(int length);
    ~ArrayInt();

public:
	void erase();
	int& operator[](int index);
	int get_length();
	void print();

	void resize(int newLength);
	void insert_before(int value, int index);
	void push_back(int value) { insert_before(value, m_length); }

	void pop_back();
	void pop_front();

	void sort();

private:
	int median_index(const int first, const int last);
	void swap(const int ia, const int ib);
	void sort_inserts(const int first, const int last);
	void sort(const int first, const int last);
};

#endif // !_LESSON4_HPP_
