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
		Ace = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 11,
		Queen = 12,
		King = 13
	};

private:
	Card::Suites m_suite;
	Card::Values m_value;
	bool m_faced_up;

public:
	void set(Card::Suites suite, Card::Values value, bool faced_up);

	Card::Suites get_suite() const { return m_suite; }
	Card::Values get_value() const;
	int get_value(bool is_ace_11) const;

	bool is_face_up() const { return m_faced_up; }
	void face_flip() { m_faced_up = !m_faced_up; }

	const string p() const;
	
public:
	Card();
	Card(Card::Suites suite, Card::Values value, bool faced_up);

	friend ostream& operator<<(ostream& os, const Card& aCard);
};

ostream& operator<<(ostream& os, const Card& card);

class Hand {
protected:
	vector<Card*> m_cards;

public:
	Hand();
	~Hand();

public:
	const vector<Card*> get_cards() const;
	void add_card(Card* pcard);
	void clear();
	bool is_ace_11() const;
	int get_total() const;
};

class GenericPlayer : public Hand{
protected:
	string m_name;

public:
	GenericPlayer();
	GenericPlayer(string name);

	virtual ~GenericPlayer();

public:
	virtual bool is_hitting() const = 0;
	bool is_boosted() const;
	void set_boost() const;

	const char* get_name() const;

	friend ostream& operator<<(ostream& os, const GenericPlayer& gp);
};

ostream& operator<<(ostream& os, const GenericPlayer& gp);

class Player : public GenericPlayer {
public:
    Player();
    Player(const string& name);
    
    virtual ~Player();
    
    virtual bool is_hitting() const;
    
    void set_win() const;
    void set_lose() const;
    void set_push() const;
};

class House : public GenericPlayer {
public:
    House();
    House(const string& name);
    
    virtual ~House();
    
    virtual bool is_hitting() const;
    
    void flip_first_card();
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
