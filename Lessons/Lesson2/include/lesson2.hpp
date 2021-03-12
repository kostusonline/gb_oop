#ifndef _LESSON2_HPP_
#define _LESSON2_HPP_

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

// Part 1
//

class Person {
public:
    // 'class' gives scoped calls of enums
	enum class Sex {
		Unknown = 0,
		Male,
		Female
	};
	static string sex_string(Person::Sex sex);
	
protected:
	string m_fname;
	int m_age;
	Sex m_sex;
	double m_weight;

public:
	void set_person(const string& fname, int age, Person::Sex sex, double weight);

public:
	Person();
	Person(const string& fname, int age, Person::Sex sex, double weight);

public:
	virtual void print();
};

class Student : public Person {
	static int m_count;
public:
	static void reset_count() { m_count = 0; };
	static int get_count() { return m_count; };

protected:
	int m_year;

public:
	int set_year(int year);
	int next_year();

public:
	Student();
	Student(int year);
	Student(int year, const string& fname, int age, Person::Sex sex, double weight);
	~Student();

public:
	virtual void print() override;
};

// Part 2
//

class Fruit{
	string m_name;
	string m_color;

public:
	void set_name(const char* name);
	void set_color(const char* color);
	
	virtual const char* get_name() const;
	const char* get_color() const;

public:
	Fruit();
	Fruit(const char* name, const char* color);
};

class Apple : public Fruit{
public:
	Apple();
	Apple(const char* color);

public:
	virtual const char* get_name() const override;
};

class GrannySmith : public Apple{
public:
	GrannySmith();
	GrannySmith(const char* color);

public:
	virtual const char* get_name() const override;
};

class Banana : public Fruit{
public:
	Banana();
	Banana(const char* color);

public:
	virtual const char* get_name() const override;
};

#endif // !_LESSON2_HPP_
