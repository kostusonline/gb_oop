#include "lesson2.hpp"

using namespace std;

// Part 1
//

void Person::set_person(const string& fname, int age, Person::Sex sex, double weight) {
		m_fname = fname;
		m_age = age;
		m_sex = sex;
		m_weight = weight;
	}

Person::Person() : m_age(0), m_sex(Person::Sex::Unknown), m_weight(0) {
	auto b = m_fname.empty();
};

Person::Person(const string& fname, int age, Person::Sex sex, double weight) {
	set_person(fname, age, sex, weight);
};

/*static*/ string Person::sex_string(Person::Sex sex){
	string s;
	if (sex == Person::Sex::Male)
		s = "Male";
	else if (sex == Person::Sex::Female)
		s = "Female";
	else
		s = "Unknown";
	return s;
};

void Person::print() {
	cout 
		<< m_fname << ", "
		<< Person::sex_string(m_sex) << ", "
		<< m_age << " y.o., "
		<< m_weight << " kg"
		<< endl;
};

int Student::m_count;

int Student::set_year(int year) {
	if (year < 0)
		year = 0;
	m_year = year;
	return m_year;
};

int Student::next_year() { 
	return ++m_year; 
};

Student::Student() : Person() {
	m_count++;
	set_year(0);
};

Student::Student(int year) : Person() {
	m_count++;
	set_year(year);
};

Student::Student(int year, const string& fname, int age, Person::Sex sex, double weight)
		: Person(fname, age, sex, weight) {
	m_count++;
	set_person(fname, age, sex, weight);
	set_year(year);
};

void Student::print() {
	cout 
		<< m_fname << ", "
		<< Person::sex_string(m_sex) << ", "
		<< m_age << " y.o., "
		<< m_weight << " kg, "
		<< m_year << " year"
		<< endl;
};

// Part 2
//

void Fruit::set_name(const char* name){
	m_name = name;
}

void Fruit::set_color(const char* color){
	m_color = color;
}
	
/*virtual*/ const char* Fruit::get_name() const { 
	return m_name.c_str(); 
}

const char* Fruit::get_color() const {
	return m_color.c_str();
}

static const char* FRUIT_NAME_DEF = "fruit";
static const char* FRUIT_COLOR_DEF = "transparent";

Fruit::Fruit(){
	set_name(FRUIT_NAME_DEF);
	set_color(FRUIT_COLOR_DEF);
}

Fruit::Fruit(const char* name, const char* color){
	set_name(name);
	set_color(color);
}

static const char* APPLE_NAME_DEF = "apple";
static const char* APPLE_COLOR_DEF = "red";

Apple::Apple(){
	set_name(APPLE_NAME_DEF);
	set_color(APPLE_COLOR_DEF);
}

Apple::Apple(const char* color){
	set_name(APPLE_NAME_DEF);
	set_color(color);
}

/*virtual*/ const char* Apple::get_name() const {
	return APPLE_NAME_DEF;
}

static const char* GS_NAME_DEF = "Granny Smith";
static const char* GS_COLOR_DEF = "green";

GrannySmith::GrannySmith(){
	set_name(GS_NAME_DEF);
	set_color(GS_COLOR_DEF);
}

GrannySmith::GrannySmith(const char* color){
	set_name(GS_NAME_DEF);
	set_color(color);
}

/*virtual*/ const char* GrannySmith::get_name() const{
	return GS_NAME_DEF;
}

static const char* BN_NAME_DEF = "banana";
static const char* BN_COLOR_DEF = "yellow";

Banana::Banana(){
	set_name(BN_NAME_DEF);
	set_color(BN_COLOR_DEF);
}

Banana::Banana(const char* color){
	set_name(BN_NAME_DEF);
	set_color(color);
}

/*virtual*/ const char* Banana::get_name() const{
	return BN_NAME_DEF;
}
