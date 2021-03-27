/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   BlackJack
*   Win10, MS VS Code, CLang/MSVS2019
*/

#include <iostream>
#include <string>

#include "bj.hpp"

using namespace std;

int main()
{
	//Card card1(Card::Suites::Hearts, Card::Values::Three, true);
	//Card card2(Card::Suites::Diamonds, Card::Values::Seven, true);
	//Card card3(Card::Suites::Crosses, Card::Values::Ace, true);
	//cout << endl << "Done" << endl;

	cout << "Welcome to Blackjack!" << endl;
    
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7){
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i){
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game game(names);
    char again = 'y';

    while (again != 'n' && again != 'N'){
        game.play();
        cout << endl << "Do you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}
