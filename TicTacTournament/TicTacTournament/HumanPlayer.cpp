/*
Alena
*/

#include "HumanPlayer.h"
#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(char piece): Player(piece) {
	//this->piece = piece;
}

HumanPlayer::~HumanPlayer() {

}

int HumanPlayer::getMove() {
	char choise = 'a';
	while (!(choise >= '0' && choise <= '8')) {
		std::cout << "Please, enter a number between 0 and 8: ";
		std::string s;
		std::cin >> s;
		if (s.size() != 1) {
			continue;
		}
		else {
			choise = s[0];
		}
	}

	//int move = choise - '0';
	return (choise - '0');

}