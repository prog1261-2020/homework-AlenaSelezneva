#include "Game.h"
#include "HumanPlayer.h"
#include <vector>
#include <sstream>


Game::Game() {
	p1 = new HumanPlayer();
	p2 = new HumanPlayer();
	board = std::vector<char>(9, '.');
	winPos = {
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}
	};
	freeCells = 9;
	curPlayer = 1;

}
bool Game::isPlaying() {
	if (freeCells == 0) {
		return false;
	}
	for (int i = 0; i < winPos.size(); i++) {
		if ((board[winPos[i][0] - 1] != '.') && (board[winPos[i][0] - 1] == board[winPos[i][1] - 1]) && (board[winPos[i][1] - 1] == board[winPos[i][2] - 1])) {
			return false;
		}
	}
	return true;

}
Player* Game::getNextPlayer() {
	return ((curPlayer % 2 == 1) ? p1 : p2);
}
std::string Game::getCurrentBoard() {
	std::stringstream ss("");
	for (int i = 0; i < 9; i++) {
		ss << board[i] << ' ';
		if (i % 3 == 2) {
			ss << "\n";
		}
	}
	return ss.str();
}
bool Game::isValid(int pos) {
	if (pos < 1 || pos > 9) {
		return false;
	}
	if (board[pos - 1] == '.') {
		return true;
	}
	return false;
}
void Game::makeMove(int pos) {
	if (curPlayer % 2 == 1) {
		board[pos - 1] = 'X';
	}
	else board[pos - 1] = '0';

	curPlayer += 1;
	freeCells -= 1;
	
}

int Game::isWon() {
	for (int i = 0; i < winPos.size(); i++) {
		if ((board[winPos[i][0] - 1] != '.') && (board[winPos[i][0] - 1] == board[winPos[i][1] - 1]) && (board[winPos[i][1] - 1] == board[winPos[i][2] - 1])) {
			if (board[winPos[i][0] - 1] == 'X') {
				return 1;
			}
			else {
				return 2;
			}
		}
	}
	return -1;
}