/*
Alena
*/

#include "HumanPlayer.h"
#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(char piece) {
	this->piece = piece;
}

HumanPlayer::~HumanPlayer(){

}

int HumanPlayer::makeMove() {
	char choise = 'a';
	while (!(choise >= '1' && choise <= '9')) {
		std::cout << "Please, enter a number between 1 and 9: ";
		std::string s;
		std::cin >> s;
		if (s.size() != 1) {
			continue;
		}
		else {
			choise = s[0];
		}
	}

	move = choise - '0';
	return (choise - '0');
	
}
int HumanPlayer::getMove() {
	return move;
}