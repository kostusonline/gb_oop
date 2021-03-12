/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 2
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include "lesson2.hpp"

using namespace std;

int main()
{
	cout << "Part 1:" << endl;

	Student::reset_count();

	Student* students[4];

	int i = 0;
	students[i++] = new Student(1, "John Connor", 20, Person::Sex::Male, 70);
	students[i++] = new Student(2, "Sarah Connor", 21, Person::Sex::Female, 55);
	students[i++] = new Student(8, "John Dogget", 40, Person::Sex::Male, 76);
	students[i++] = new Student(1, "Schwartz", 42, Person::Sex::Unknown, 200);

	cout << "Students: " << Student::get_count() << endl;

	for (int j = 0; j < i; j++)
		students[j]->print();

	cout << "Remove one student..." << endl;
	delete students[--i];
	students[i] = NULL;

	cout << "Students: " << Student::get_count() << endl;
	for (int j = 0; j < i; j++){
		students[j]->print();
		delete students[j];
	}

	cout << endl;
	cout << "Part 2:" << endl;

	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.get_name() << " is " << a.get_color() << "." << endl;
    std::cout << "My " << b.get_name() << " is " << b.get_color() << "." << endl;
    std::cout << "My " << c.get_name() << " is " << c.get_color() << "." << endl;

	Fruit* f;
	f = &c;
    std::cout << "My " << f->get_name() << " is " << f->get_color() << "." << endl;

	// output should look like this:
	// My apple is red.
	// My banana is yellow.
	// My Granny Smith apple is green.
	// + check virtual method
	
	cout << endl;
	cout << "Part 3 (see source code)" << endl;

	/*
		class Card:
			price (6 .. A);
			print;
			(overloaded operator+ ?)

		class Card fabric:
			reset fabric (new game);
			create a cards (random);

		class BlackJackMember:
			cards holder;
			returns sum on request;
			print sum;
			print cards;

		class Dealer : BlackJackMember:
			encapsulates cards fabric;
			supports dealer's rools;
			draw action;
		
		class Player : BlackJackMember:
			request card action;
			request sums action;		
			(supports player's rools;)

		class Game:
			supports main cycle (state machine);
			(messages, exit/next/stop-checker;)
	*/

	cout << endl << "Done" << endl;
	return 0;
}
