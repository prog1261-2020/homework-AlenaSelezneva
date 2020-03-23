#include "Board.h"

Board::Board() {
	board = std::vector<char>(9, '.');
	freeCells = 9;
}

bool Board::isPlaying(){
	if (freeCells == 0) {
		return false;
	}
	for (int i = 0; i < WIN_POS.size(); i++) {
		if ((board[WIN_POS[i][0] - 1] != '.') &&
			(board[WIN_POS[i][0] - 1] == board[WIN_POS[i][1] - 1]) &&
			(board[WIN_POS[i][1] - 1] == board[WIN_POS[i][2] - 1])) {
			return false;
		}
	}
}

void Board::makeMove(int pos, char piece) {
	board[pos] = piece;
	//curPlayer += 1;
	freeCells -= 1;
}

bool Board::isValid(int pos) {
	if (pos < 1 || pos > 9) {
		return false;
	}
	if (board[pos - 1] == '.') {
		return true;
	}
	return false;
}

int Board::getWinningMove(char piece) {
	for (int i = 0; i < WIN_POS.size(); i++) {
		int combo = 0;
		for (int j = 0; j < 3; j++) {
			if (board[WIN_POS[i][j] - 1] == piece)
				++combo;
		}
		if (combo == 2) {
			for (int j = 0; j < 3; j++) {
				if (board[WIN_POS[i][j] - 1] == '.')
					return WIN_POS[i][j];
			}
		}
	}
	return -1;
}