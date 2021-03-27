#include <cmath>
#include <string>
#include <iomanip>

#include "lesson7.hpp"

using namespace std;

bool Date::set(int y, int m, int d){
    int _y = m_year = y < 1 ? -1 : y > YEAR_MAX ? -1 : y;
    int _m = m_month = m < 1 ? -1 : m > 12 ? -1 : m;
    int _d = m_day = d < 1 ? -1 : d > 31 ? -1 : d; // lazy impl.

    if (_y < 0 || _m < 0 || _d < 0)
        return false;
    
    m_year = _y;
    m_month = _m;
    m_day = _d;
    return true;
}

// lazy impl.
long Date::sum() const{
    return (m_year * 365) + (m_month * 30) + m_day;
}

Date::Date(){
    m_year = 1;
    m_month = 1;
    m_day = 1;
}

Date::Date(int y, int m, int d){
    set(y, m, d);
}

Date::Date(const Date& d){
    cout << "Date::Date(Date&) called" << endl;
    set(d.year(), d.month(), d.day());
}

/*virtual*/
Date::~Date(){
}

ostream& operator<<(ostream& os, const Date& d){
    os 
        << setfill('0') << setw(4) << d.year()
        << "-"
        << setw(2) << d.month()
        << "-"
        << d.day();

    return os;
}

Date& max_date(const shared_ptr<Date>& d1, const shared_ptr<Date>& d2){
    if (d1->sum() >= d2->sum())
        return *d1;
    return *d2;
}

void swap_dates(shared_ptr<Date>& d1, shared_ptr<Date>& d2){
    d1.swap(d2);
}
