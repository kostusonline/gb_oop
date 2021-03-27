#ifndef _LESSON7_HPP_
#define _LESSON7_HPP_

#include <cstdint>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

#define YEAR_MAX 50000

class Date{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    int year() const { return m_year; }
    int month() const { return m_month; }
    int day() const { return m_day; }
    long sum() const;

    bool set(int y, int m, int d);

public:
    Date();
    Date(int y, int m, int d);
    Date(const Date& d);
    virtual ~Date();

public:
    friend ostream& operator<<(ostream& os, const Date& d);
};

/* Date-related
*/
ostream& operator<<(ostream& os, const Date& d);
Date& max_date(const shared_ptr<Date>& d1, const shared_ptr<Date>& d2);
void swap_dates(shared_ptr<Date>& d1, shared_ptr<Date>& d2);

#endif // !_LESSON7_HPP_
