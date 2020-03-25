

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

#include <ctime>

int main() {
	srand((int)time(0));

	auto board = new Board();
	Player* one = new HumanPlayer('X');
	Player* two = new AIPlayer('0', board);
	Game ticTacToe( one, two, board);
	ticTacToe.play();

}