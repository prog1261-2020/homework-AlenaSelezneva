

#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

#include <iostream>
#include <string>

const std::string boardPositions = "1 2 3\n4 5 6\n7 8 9\n\n";

int main() {

	bool isQuitting = false;

	while (!isQuitting) {
		system("cls");

		Game game;

		//game.addPlayer(Player());

		//game.play();

		while (game.isPlaying()) {
			system("cls");
			std::cout << boardPositions;
			std::cout << game.getCurrentBoard();
			Player* player = game.getNextPlayer();

			while (!game.isValid(player->getMove())) {
				player->makeMove();
			}

			game.makeMove(player->getMove());

		}

		system("cls");
		std::cout << boardPositions;
		std::cout << game.getCurrentBoard();

		int hasWon = game.isWon();
		switch (hasWon) {
		case 1:
			std::cout << "Player 1 has won\n";
			break;
		case 2:
			std::cout << "Player 2 has won\n";
			break;
		default:
			std::cout << "It is a draw\n";
		}
		system("pause");

		std::cout << "Do you want to play again?\nY - yes\nN - no\n";
		char c;
		std::cin >> c;
		while (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N')) {
			system("cls");
			std::cout << "Please, enter a valid choise:\nY - yes\nN - no\n";
			std::cin >> c;
		}

		switch (c)
		{
		case 'y':
		case 'Y':
			break;
		case 'n':
		case 'N': 
			isQuitting = true;
			break;
		default:
			break;
		}
		

	}

	



}

