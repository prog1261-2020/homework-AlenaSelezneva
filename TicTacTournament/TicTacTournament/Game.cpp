#include "Game.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
/*
Alena
*/

#include <vector>
#include <sstream>


Game::Game(Player* one, Player* two, Board* board) {
	p1 = one;
	p2 = two;
	this->board = board;
	curPlayer = 1;
}
bool Game::isPlaying() {
	if (board->isWinner('X')) {
		return false;
	}
	if (board->isWinner('0')) {
		return false;
	}

	/*if (this->isWon() != ' ') {
		return false;
	}*/
	/*if (board->isWinner('X')) {
		return false;
	}
	if (board->isWinner('0')) {
		return false;
	}*/
	for (int i = 0; i < 9; i++) {
		if (board->getBoard()[i] == ' ') {
			return true;
		}
	}
	return false;
}
Player* Game::getNextPlayer() {
	return ((curPlayer % 2 == 1) ? p1 : p2);
}

std::string Game::getCurrentBoard() {
	std::stringstream ss("");
	for (int i = 0; i < 9; i++) {
		ss << board->getBoard()[i] << ' ';
		if (i % 3 == 2) {
			ss << "\n";
		}
	}
	return ss.str();
}
bool Game::isValid(int pos) {
	return board->isValidMove(pos);
}
void Game::makeMove(int pos) {
	board->makeMove(getNextPlayer()->getPiece(), pos);
	curPlayer += 1;

}

char Game::isWon() {
	if (board->isWinner('X')) {
		return 'X';
	}
	if (board->isWinner('0')) {
		return '0';
	}
	return ' ';
}

void Game::play() {
	while (this->isPlaying()) {
		system("cls");
		std::cout << board->getBoardPlaces() << "\n"; //boardPositions;
		std::cout << board->getCurrentBoard() << "\n"; //game.getCurrentBoard();
		Player* player = getNextPlayer();

		int move = -1;
		while (!board->isValidMove(move)) {
			move = player->getMove();
		}

		makeMove(move);

	}
	system("cls");
	std::cout << board->getBoardPlaces() << "\n"; //boardPositions;
	std::cout << board->getCurrentBoard() << "\n"; //game.getCurrentBoard();
}