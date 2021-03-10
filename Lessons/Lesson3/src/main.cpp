/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 3
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include "lesson3.hpp"

using namespace std;

int main()
{
	// P1 /////////////////////////////////////////////////////////////////
	cout << "Part 1:" << endl;

	Parallelogram pg(12, 18, 45);
	cout << "Parallelogram(12,18,45) area is " << pg.get_area() << endl; 

	Rectangle rc(12, 18);
	cout << "Rectangle(12,18) area is " << rc.get_area() << endl; 

	Square sq(12);
	cout << "Square(12) area is " << sq.get_area() << endl; 

	Rhombus rb(12, 18);
	cout << "Rhombus(12,18) area is " << rb.get_area() << endl; 

	Circle cr(12);
	cout << "Circle(12) area is " << cr.get_area() << endl; 

	// P2 /////////////////////////////////////////////////////////////////
	cout << endl << "Part 2" << endl;

	Car c;
	cout << endl;

	PassengerCar p("Peugeot", "308");
	cout << endl;

	Bus b("Toyota", "Hiace");
	cout << endl;

	Van v("Toyota", "Ipsum");
	cout << endl;

	// P3 /////////////////////////////////////////////////////////////////
	cout << endl << "Part 3" << endl;

	Fraction f1(3, 4);
	Fraction f2(4, 7);
	Fraction f3(7, 2);

	Fraction fr1 = f1 + f2 - f3;
	cout 
		<< "fr1 = " << f1.p() << " + " << f2.p() << " + " << f3.p() << " = " 
		<< fr1.p() << " (" << fr1.solve() << ")" << endl;

	Fraction fr2 = f1 * f2 / f3;
	cout 
		<< "fr2 = " << f1.p() << " * " << f2.p() << " / " << f3.p() << " = " 
		<< fr2.p() << " (" << fr2.solve() << ")" << endl;

	fr2 = -fr2;	
	cout 
		<< "-fr2 = " << fr2.p() << endl;

	Fraction f4(3, 4);
	cout << f4.p() << " == " << f1.p() << " ? " << (f4 == f1 ? "yes" : "no") << endl;
	cout << f4.p() << " >= " << f1.p() << " ? " << (f4 >= f1 ? "yes" : "no") << endl;
	cout << f4.p() << " < " << f1.p() << " ? " << (f4 < f1 ? "yes" : "no") << endl;
	cout << f4.p() << " > " << f2.p() << " ? " << (f4 > f2 ? "yes" : "no") << endl;

	// P4 /////////////////////////////////////////////////////////////////
	cout << endl << "Part 4 (see code)" << endl;
	
	Card card1(Card::Suites::Hearts, Card::Values::Three, true);
	Card card2(Card::Suites::Diamonds, Card::Values::Seven, true);
	Card card3(Card::Suites::Crosses, Card::Values::Ace, true);

	cout << endl << "Done" << endl;
	return 0;
}
