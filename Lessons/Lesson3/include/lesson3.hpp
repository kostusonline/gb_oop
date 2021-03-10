#ifndef _LESSON3_HPP_
#define _LESSON3_HPP_

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

/* https://docs.google.com/document/d/1Np3OUm1bl2D_HUHdHOQPL-vLCas5H0o9yXRMduhoL8o/edit
*/

// Part 1
//

/*	Создать абстрактный класс Figure (фигура). 
	Его наследниками являются классы Parallelogram (параллелограмм) и 
	Circle (круг). 
	Класс Parallelogram — базовый для классов 
	Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
	Для всех классов создать конструкторы. 
	Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
	Во всех остальных классах переопределить эту функцию, 
	исходя из геометрических формул нахождения площади.
*/

// struct Point {
// 	double x;
// 	double y;
// };

// class Line {
// 	Point m_p[2];
// 	double m_len_calculated;
// public:
// 	void set(Point p0, Point p1);
// 	double calc();
// 	double get_length();
// public:
// 	Line();
// 	Line(Point p0, Point p1);
// };

class Figure {
public:
	virtual const char* get_type() const = 0;
	virtual double get_area() = 0;
public:
	Figure(){}
};

/* Parallelogram:
	- left-top point;
	- one side length,
	- second side length;
	- angle between sides;
*/

#define PG_TYPE "parallelogram"
class Parallelogram : public Figure {
protected:
	double m_a;
	double m_b;
	double m_alfa;
public:
	virtual const char* get_type() const override;
	virtual double get_area() override;
public:
	Parallelogram();
	Parallelogram(double a, double b, double alfa);
};

#define RC_TYPE "rectangle"
class Rectangle : public Parallelogram {
public:
	virtual const char* get_type() const override;
	virtual double get_area() override;
public:
	Rectangle();
	Rectangle(double a, double b);
	// ^ angle between sides always pi/2
};

#define SQ_TYPE "square"
class Square : public Parallelogram {
public:
	virtual const char* get_type() const override;
	virtual double get_area() override;
public:
	Square();
	Square(double ab);
	// ^ angle between sides always pi/2 and sides are equal
};

#define RB_TYPE "rhombus"
class Rhombus : public Parallelogram {
public:
	virtual const char* get_type() const override;
	virtual double get_area() override;
public:
	Rhombus();
	Rhombus(double ab, double alfa);
};

#define CR_TYPE "circle"
class Circle : public Figure {
	double m_r;
public:
	virtual const char* get_type() const override;
	virtual double get_area() override;
public:
	Circle();
	Circle(double r);
};

// Part 2
//

/*	Создать класс Car (автомобиль) с полями 
	company (компания) и model (модель). 
	Классы-наследники: 
	PassengerCar (легковой автомобиль) и 
	Bus (автобус). 
	От этих классов наследует класс Minivan (минивэн). 
	Создать конструкторы для каждого из классов, 
	чтобы они выводили данные о классах. 
	Создать объекты для каждого из классов и посмотреть, 
	в какой последовательности выполняются конструкторы. 
	Обратить внимание на проблему «алмаз смерти».
*/

class Car {
protected:
	string m_brand;
	string m_model;
public:
	Car();
	Car(const char* brand, const char* model);
};

class PassengerCar : virtual public Car {
public:
	PassengerCar();
	PassengerCar(const char* brand, const char* model);
};

class Bus : virtual public Car {
public:
	Bus();
	Bus(const char* brand, const char* model);
};

class Van : public PassengerCar, public Bus  {
public:
	Van();
	Van(const char* brand, const char* model);
};

// Part 3
//

/*	Создать класс Fraction (дробь). 
	Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
	Предусмотреть, чтобы знаменатель не был равен 0. 
	Перегрузить:
		математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
		унарный оператор (-)
		логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
	Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, 
	попробуйте перегрузить один через другой.
	Продемонстрировать использование перегруженных операторов.
*/

class Fraction {
	int m_n; //..umerator;
	int m_d; //..enominator;

public:
	void set(int n, int d); 
	const int get_num() const;
	const int get_denom() const;

	const string p() const;

	const double solve() const;
	operator double() { return solve(); }

	const Fraction operator+(const Fraction& rf) const;
	const Fraction operator-(const Fraction& rf) const;
	const Fraction operator*(const Fraction& rf) const;
	const Fraction operator/(const Fraction& rf) const;

	const Fraction operator-() const; // destination - new object
	Fraction operator-();

	bool operator==(const Fraction& rf) const;
	bool operator!=(const Fraction& rf) const { return !operator==(rf); }

	bool operator<(const Fraction& rf) const;
	bool operator>=(const Fraction& rf) const { return !operator<(rf); }

	bool operator>(const Fraction& rf) const;
	bool operator<=(const Fraction& rf) const { return !operator>(rf); }

public:
	Fraction();
	Fraction(int n, int d);
	Fraction(const Fraction& rf);
};

// Part 4
//

/*	Создать класс Card, описывающий карту в игре БлэкДжек. 
	У этого класса должно быть три поля: 
		масть, 
		значение карты и 
		положение карты (вверх лицом или рубашкой). 
	Сделать поля масть и значение карты типом перечисления (enum). 
	Положение карты - тип bool. 
	Также в этом классе должно быть два метода: 
		метод Flip(), который переворачивает карту, т.е. 
			если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
		метод GetValue(), который возвращает значение карты, 
			пока можно считать, что туз = 1.
*/

class Card {
public:
	enum class Suites {
		Unknown = 0,
		Crosses, 
		Diamonds,
		Spades,
		Hearts
	};

	enum class Values : int {
		Unknown = 0,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 10,
		Queen = 10,
		King = 10,
		Ace = 1
	};

private:
	Card::Suites m_suite;
	Card::Values m_value;
	bool m_faced_up;

public:
	void set(Card::Suites suite, Card::Values value, bool faced_up);

	Card::Suites get_suite() { return m_suite; }
	int get_value() { return static_cast<int>(m_value); }

	bool is_face_up() { return m_faced_up; }
	void face_flip() { m_faced_up = !m_faced_up; }

	const string p() const;
	
public:
	Card();
	Card(Card::Suites suite, Card::Values value, bool faced_up);
};

#endif // !_LESSON3_HPP_
