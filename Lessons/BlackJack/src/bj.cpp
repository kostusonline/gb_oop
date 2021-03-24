#include <cmath>
#include <string>
#include "bj.hpp"

using namespace std;

/************************************************************** 
				Card
**************************************************************/

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

Card::Values Card::get_value() const {
	return m_value;
}

int Card::get_value(bool is_ace_11) const { 
	if (m_value == Card::Values::Ace){
		return is_ace_11 ? 11 : static_cast<int>(m_value);
	}
	return static_cast<int>(m_value); 
}

ostream& operator<<(ostream& os, const Card& card)
{
    const string SUITS[] = { "?", "C", "D", "H", "S" };
    const string VALUES[] = { "?", "A", 
							 "2", "3", "4", "5", "6", "7", "8", "9","10", 
						     "J", "Q", "K" };
    
	Card::Suites s = card.get_suite();
	int is = -1;
	Card::Values v = card.get_value();
	int iv = -1;

	switch (s) {
		case Card::Suites::Crosses: is = 1; break;
		case Card::Suites::Diamonds: is = 2; break;
		case Card::Suites::Hearts: is = 3; break;
		case Card::Suites::Spades: is = 4; break;
		default: is = 0; break;
	}

	switch (v){
		case Card::Values::Ace: iv = 1; break;
		case Card::Values::Two: iv = 2; break;
		case Card::Values::Three: iv = 3; break;
		case Card::Values::Four: iv = 4; break;
		case Card::Values::Five: iv = 5; break;
		case Card::Values::Six: iv = 6; break;
		case Card::Values::Seven: iv = 7; break;
		case Card::Values::Eight: iv = 8; break;
		case Card::Values::Nine: iv = 9; break;
		case Card::Values::Ten: iv = 10; break;
		case Card::Values::Jack: iv = 11; break;
		case Card::Values::Queen: iv = 12; break;
		case Card::Values::King: iv = 13; break;
		default: iv = 0; break;
	}

    if (card.is_face_up())
        os << VALUES[iv] << SUITS[is];
    else
        os << "XX";
    
    return os;
}

/************************************************************** 
				Hand
**************************************************************/

Hand::Hand(){
}

Hand::~Hand(){
	clear();
}

const vector<Card*> Hand::get_cards() const{
	return m_cards;
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

bool Hand::is_ace_11() const { 
	// just stub for now
	return true;
}

int Hand::get_total() const {
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

/************************************************************** 
				GenericPlayer
**************************************************************/

GenericPlayer::GenericPlayer(){
	m_name.clear();
}

GenericPlayer::GenericPlayer(string name){
	m_name = name;
}

GenericPlayer::~GenericPlayer(){
}

bool GenericPlayer::is_boosted() const {
	return get_total() > 21;
};

void GenericPlayer::set_boost() const {
	cout << m_name << " boosted!" << endl;
}

const char* GenericPlayer::get_name() const {
	return m_name.c_str();
}

ostream& operator<<(ostream& os, const GenericPlayer& gp)
{
    os << gp.get_name() << ": ";
    
    vector<Card*>::const_iterator ci;
    if (!gp.get_cards().empty())
    {
		int cc = gp.get_cards().size();
		int cn = 0;
        for (ci = gp.get_cards().begin(); ci != gp.get_cards().end(); ++ci)
        {
			cn++;
            os << *(*ci);
			if (cn < cc)
				os << " | ";
        }
        
        if (gp.get_total() != 0)
        {
            cout << "(" << gp.get_total() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    
    return os;
}

/************************************************************** 
				Player
**************************************************************/

Player::Player(){
	m_name.clear();
}

Player::Player(const string& name){
	m_name = name;
}

Player::~Player(){
}

bool Player::is_hitting() const
{
    cout << m_name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::set_win() const
{
    cout << m_name << " WINS :-)" << endl;
}

void Player::set_lose() const
{
    cout << m_name << " loses :-(" << endl;
}

void Player::set_push() const
{
    cout << m_name << " pushes 8-|" << endl;
}

/************************************************************** 
				House
**************************************************************/

House::House(){
}

House::House(const string &name){
	m_name = name;
}

House::~House(){
}

bool House::is_hitting() const {
    return (get_total() <= 16);
}

void House::flip_first_card()
{
    if (!(m_cards.empty()))
    {
		Card* pcard = get_cards()[0];
        pcard->face_flip();
    }
    else
    {
        cout << "No card to flip!" << endl;
    }
}

/************************************************************** 
				Game
**************************************************************/

Game::Game(){
}

Game::Game(vector<string>& names){
	m_names = names;
}

bool Game::play(){
	// stub
	return true;
}
