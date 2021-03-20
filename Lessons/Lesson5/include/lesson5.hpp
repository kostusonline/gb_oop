#ifndef _LESSON5_HPP_
#define _LESSON5_HPP_

#include <cstdint>
#include <string>
#include <cassert>

using namespace std;

template <typename T>
class Pair1 {
private:
    const T m_first;
    const T m_second;
public:
    T first() const { return m_first; }
    T second() const { return m_second; }
public:
    Pair1(T f, T s) : m_first(f), m_second(s) { }
};

template <typename T1, typename T2>
class Pair {
protected:
    const T1 m_first;
    const T2 m_second;
public:
    T1 first() const { return m_first; }
    T2 second() const { return m_second; }
public:
    Pair(T1 f, T2 s) : m_first(f), m_second(s) { }
};

template <typename T>
class StringValuePair : public Pair<string, T> {
public:
    StringValuePair(string f, T s) : Pair<string, T>(f, s) { }
};

#endif // !_LESSON5_HPP_
