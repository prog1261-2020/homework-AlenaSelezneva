/*
Alena
*/

#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <ctime>

#include <iostream>
#include <string>

const std::string boardPositions = "1 2 3\n4 5 6\n7 8 9\n\n";

int main() {
	std::cout << "HI";
	srand((int)time(0));

	bool isQuitting = false;

	while (!isQuitting) {

		
		char humans = 'a';
		while (!(humans >= '0' && humans <= '2')) {
			std::cout << "How many human players do you want? (0, 1 or 2)\n";
			std::string s;
			std::cin >> s;
			if (s.size() != 1) {
				continue;
			}
			else {
				humans = s[0];
			}
		}


		system("cls");

		Game game(humans - '0');

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

