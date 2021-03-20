#ifndef _BJ_HPP_
#define _BJ_HPP_

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

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
	int get_value(bool is_ace_11);

	bool is_face_up() { return m_faced_up; }
	void face_flip() { m_faced_up = !m_faced_up; }

	const string p() const;
	
public:
	Card();
	Card(Card::Suites suite, Card::Values value, bool faced_up);
};

class Hand {
protected:
	vector<Card*> m_cards;

public:
	Hand();
	~Hand();

public:
	void add_card(Card* pcard);
	void clear();
	bool is_ace_11();
	int get_total();
};

class GenericPlayer : public Hand{
	string m_name;

public:
	GenericPlayer();
	GenericPlayer(string name);

public:
	virtual bool is_hitting() = 0;
	bool is_boosted();
	void set_boost();
};

class Game{
	vector<string> m_names;

public:
	Game();
	Game(vector<string>& names);

public:
	bool play();
};

#endif // !_BJ_HPP_
