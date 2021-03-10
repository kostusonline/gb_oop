#include <cmath>
#include <string>
#include "lesson3.hpp"

using namespace std;

#define PI 3.14159265358979323846

// Part 1
//

// Parallelogram
/*virtual*/ const char* Parallelogram::get_type() const { return PG_TYPE; }

/*virtual*/ double Parallelogram::get_area(){
	double s = m_a * m_b * sin(m_alfa * (PI / 180));
	return s;
}

Parallelogram::Parallelogram() : Figure() {
	m_a = m_b = m_alfa = 0;
}

Parallelogram::Parallelogram(double a, double b, double alfa) : Figure() {
	m_a = a;
	m_b = b;
	m_alfa = alfa;
}

//static const char* RC_TYPE = "rectangle";
/*virtual*/ const char* Rectangle::get_type() const { return RC_TYPE; }

/*virtual*/ double Rectangle::get_area(){
	return m_a * m_b;
}

Rectangle::Rectangle() : Parallelogram() {
	m_a = m_b = m_alfa = 0;
}

Rectangle::Rectangle(double a, double b) : Parallelogram(a, b, 90) {
}

//static const char* SQ_TYPE = "square";
/*virtual*/ const char* Square::get_type() const { return SQ_TYPE; }

/*virtual*/ double Square::get_area(){
	return m_a * m_b;
}

Square::Square() : Parallelogram() {
	m_a = m_b = m_alfa = 0;
}

Square::Square(double ab) : Parallelogram(ab, ab, 90) {
}

//static const char* RB_TYPE = "rhombus";
/*virtual*/ const char* Rhombus::get_type() const { return RB_TYPE; }

/*virtual*/ double Rhombus::get_area(){
	return Parallelogram::get_area();
}

Rhombus::Rhombus() : Parallelogram() {
	m_a = m_b = m_alfa = 0;
}

Rhombus::Rhombus(double ab, double alfa) : Parallelogram(ab, ab, alfa) {
}

//static const char* CR_TYPE = "circle";
/*virtual*/ const char* Circle::get_type() const { return CR_TYPE; }

/*virtual*/ double Circle::get_area(){
	return PI * m_r * m_r;
}

Circle::Circle() : Figure() {
	m_r = 0;
}

Circle::Circle(double r) : Figure() {
	m_r = r;
}

// Part 2
//

Car::Car(){
	auto b = m_brand.empty();
	b = m_model.empty();
	cout << "Car::Car(): Hello!" << endl;
}

Car::Car(const char* brand, const char* model) {
	m_brand = brand;
	m_model = model;
	cout << "Car::Car(with args): Hello!" << endl;
}

PassengerCar::PassengerCar() : Car() {
	auto b = m_brand.empty();
	b = m_model.empty();
	cout << "PassengerCar::PassengerCar(): Hello!" << endl;
}

PassengerCar::PassengerCar(const char* brand, const char* model) : Car(brand, model) {
	cout << "PassengerCar::PassengerCar(with args): Hello!" << endl;
}

Bus::Bus() : Car() {
	auto b = m_brand.empty();
	b = m_model.empty();
	cout << "Bus::Bus(): Hello!" << endl;
}

Bus::Bus(const char* brand, const char* model) : Car(brand, model) {
	cout << "Bus::Bus(with args): Hello!" << endl;
}

Van::Van() : PassengerCar(), Bus(), Car() {
	auto b = m_brand.empty();
	b = m_model.empty();
	cout << "Van::Van(): Hello!" << endl;
}

Van::Van(const char* brand, const char* model) : PassengerCar(), Bus(), Car(brand, model) {
	cout << "Van::Van(with args): Hello!" << endl;
}

// Part 3
//

void Fraction::set(int n, int d) {
	m_n = n;
	if (d != 0){
		m_d = d;
	}
	else {
		m_d = 1;
	}
}

const int Fraction::get_num() const { return m_n; }
const int Fraction::get_denom() const { return m_d; }

const string Fraction::p() const{
	string s = to_string(m_n) + "/" + to_string(m_d); // "/"s ?
	return s;
}

const double Fraction::solve() const{
	return static_cast<double>(m_n) / static_cast<double>(m_d);
}

const Fraction Fraction::operator+(const Fraction& rf) const {
	return Fraction(m_n + rf.get_num(), m_d + rf.get_denom());
}

const Fraction Fraction::operator-(const Fraction& rf) const {
	return Fraction(m_n - rf.get_num(), m_d - rf.get_denom());
}

const Fraction Fraction::operator*(const Fraction& rf) const {
	return Fraction(m_n * rf.get_num(), m_d * rf.get_denom());
}

const Fraction Fraction::operator/(const Fraction& rf) const {
	return Fraction(m_n * rf.get_denom(), m_d * rf.get_num());
}

const Fraction Fraction::operator-() const{
	return Fraction(-m_n, m_d);
}

Fraction Fraction::operator-() {
	return Fraction(-m_n, m_d);
}

bool Fraction::operator==(const Fraction& rf) const{
	// lazy way
	return abs(solve() - rf.solve()) <= DBL_MIN;
}

bool Fraction::operator<(const Fraction& rf) const{
	// lazy way
	return solve() < rf.solve();
}

bool Fraction::operator>(const Fraction& rf) const{
	// lazy way
	return solve() > rf.solve();
}

Fraction::Fraction(){
	// lazy way
	m_n = m_d = 1;
}

Fraction::Fraction(int n, int d){
	set(n, d);
}

Fraction::Fraction(const Fraction& rf){
	set(rf.get_num(), rf.get_denom());
}

// Part 4
//

void Card::set(Card::Suites suite, Card::Values value, bool faced_up){
	m_suite = suite;
	m_value = value;
	m_faced_up = faced_up;
}

Card::Card() {
	set(Card::Suites::Unknown, Card::Values::Unknown, false);
}

Card::Card(Card::Suites suite, Card::Values value, bool faced_up) {
	set(suite, value, faced_up);	
}
