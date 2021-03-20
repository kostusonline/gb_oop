#include <cmath>
#include <string>
#include "bj.hpp"

using namespace std;

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

int Card::get_value(bool is_ace_11) { 
	if (m_value == Card::Values::Ace){
		return is_ace_11 ? 11 : static_cast<int>(m_value);
	}
	return static_cast<int>(m_value); 
}

Hand::Hand(){
}

Hand::~Hand(){
	clear();
}

void Hand::add_card(Card* pcard){
	m_cards.push_back(pcard);
}

void Hand::clear(){
	if (m_cards.size() <= 0)
		return;

	auto it = m_cards.begin();
    while(it != m_cards.end())
    {
        Card* pcard = *it;
		if (pcard == nullptr)
			continue;

		delete pcard;
		pcard = nullptr;
        ++it;
    }

	m_cards.clear();
}

bool Hand::is_ace_11(){
	// just stud for now
	return true;
}

int Hand::get_total(){
	if (m_cards.size() <= 0)
		return 0;

	int total = 0;
	auto it = m_cards.begin();
    while(it != m_cards.end())
    {
        Card* pcard = *it;
		if (pcard == nullptr)
			continue;

		total += pcard->get_value(is_ace_11());
        ++it;
    }

	return total;
}

GenericPlayer::GenericPlayer(){
	m_name.clear();
}

GenericPlayer::GenericPlayer(string name){
	m_name = name;
}

bool GenericPlayer::is_boosted(){
	return get_total() > 21;
};

void GenericPlayer::set_boost(){
	cout << m_name << " boosted!" << endl;
}

Game::Game(){
}

Game::Game(vector<string>& names){
	m_names = names;
}

bool Game::play(){
	// stub
	return true;
}
