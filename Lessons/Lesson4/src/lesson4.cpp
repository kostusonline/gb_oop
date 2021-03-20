#include <cmath>
#include <string>
#include "lesson4.hpp"

using namespace std;

// Part 1
//

/*public*/
ArrayInt::ArrayInt() {
	m_length = 0;
	m_data = nullptr;
}

/*public*/
ArrayInt::ArrayInt(int length) {
    assert(length >= 0);
    m_data = length > 0 ? new int[length] : nullptr;
	m_length = length;
}

/*public*/
ArrayInt::~ArrayInt() {
    delete[] m_data;
}

/*public*/
void ArrayInt::erase() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

/*public*/
int ArrayInt::get_length() { 
	return m_length; 
}

/*public*/
int& ArrayInt::operator[](int index){
	assert(index >= 0);
	assert(index < m_length);
	assert(m_length > 0);
	return m_data[index];
}

/*public*/
void ArrayInt::resize(int new_len)
{
	if (new_len == m_length)
		return;

	if (new_len <= 0)
	{
		erase();
		return;
	}
 
	int *new_data = new int[new_len];

	if (m_length > 0)
	{
		int elementsToCopy = (new_len > m_length) ? m_length : new_len;
		for (int index = 0; index < elementsToCopy; ++index)
			new_data[index] = m_data[index];
	}

	delete[] m_data;

	m_data = new_data;
	m_length = new_len;
}

/*public*/
void ArrayInt::insert_before(int value, int index)
{
	assert(index >= 0 && index <= m_length);

	int *new_data = new int[m_length + 1];
	for (int before = 0; before < index; ++before)
		new_data[before] = m_data[before];

	new_data[index] = value;
	for (int after = index; after < m_length; ++after)
		new_data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = new_data;
	++m_length;
}

/*public*/
void ArrayInt::pop_back(){
	if (m_length <= 0)
		return;
	
	resize(m_length - 1);
}

/*public*/
void ArrayInt::pop_front(){
	if (m_length <= 0)
		return;

	int new_len = m_length - 1;
	if ((new_len) <= 0){
		erase();
		return;
	}

	int *new_data = new int[new_len];
	for (int i = 0; i < new_len; ++i)
		new_data[i] = m_data[i + 1];

	delete[] m_data;

	m_data = new_data;
	m_length = new_len;
}

/*public*/
void ArrayInt::print(){
	if (m_length <= 0 || m_data == nullptr)
		return;
	
	for (int i = 0; i < m_length; ++i){
		cout << m_data[i] << " ";
	}
	cout << endl;
}

/*private*/
int ArrayInt::median_index(const int first, const int last){
	if (m_length <= 0 || m_data == nullptr)
		return -1;

    int n1 = m_data[first];
    int n2 = m_data[last / 2];
    int n3 = m_data[last];

    if ((n2 < n1 && n1 < n3) || (n2 > n1 && n1 > n3))
        return 0;

    if ((n1 < n2 && n2 < n3) || (n1 > n2 && n2 > n3))
        return last / 2;

    return last;
}

/*private*/
void ArrayInt::swap(const int ia, const int ib){
	if (m_length <= 0 || m_data == nullptr)
		return;

    int i = m_data[ia];
    m_data[ia] = m_data[ib];;
    m_data[ib] = i;
}

/*public; entry point*/
void ArrayInt::sort(){
	if (m_length <= 0 || m_data == nullptr)
		return;

	sort(0, m_length - 1);
}

/*private*/
void ArrayInt::sort_inserts(const int first, const int last){
	if (m_length <= 0 || m_data == nullptr)
		return;

    for (int j = first + 1; j <= last; j++){
        int key = m_data[j];
        int i = j - 1;
        while (i >= first && m_data[i] > key){
            m_data[i + 1] = m_data[i];
            i--;
        }
        m_data[i+1] = key;
    }
}

static const int SORT_MIN = 10;

/*private, actual sort*/
void ArrayInt::sort(const int first, const int last){
	assert(first >= 0 && last < m_length && first <= last);
	if (m_length <= 0 || m_data == nullptr)
		return;

    if (last - first > SORT_MIN){
        int med = median_index(first, last);
		if (med < 0)
			return;

        swap(med, (first + last) / 2);
        int i = first;
        int j = last;
        int x = m_data[(first + last) / 2];
        do {
            while (m_data[i] < x) i++;
            while (m_data[j] > x) j--;
            if(i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        } while (i <= j);

        sort(i, last);
        sort(first, j);
    } else {
        sort_inserts(first, last);
        return;
    }
}

