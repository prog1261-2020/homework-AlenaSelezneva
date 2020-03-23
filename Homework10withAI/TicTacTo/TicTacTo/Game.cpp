#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <vector>
#include <sstream>


Game::Game(int humans) {
	board = new Board();

	switch (humans) {
	case 0: 
		p1 = new AIPlayer('X', board);
		p2 = new AIPlayer('0', board);
		break;
	case 1:
		p1 = new HumanPlayer('X');
		p2 = new AIPlayer('0', board);
		break;
	case 2:
		p1 = new HumanPlayer('X');
		p2 = new HumanPlayer('0');
		break;
	default:
		p1 = new HumanPlayer('X');
		p2 = new AIPlayer('0', board);
		break;
	}


	//p1 = new HumanPlayer('X');
	//p2 = new HumanPlayer('0');

	//p1 = new AIPlayer('X', board);
	//p2 = new AIPlayer('0', board);

	/*board = std::vector<char>(9, '.');
	winPos = {
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}
	};*/
	/*board = new Board();*/
	//freeCells = 9;
	curPlayer = 1;

}
bool Game::isPlaying() {
	/*if (freeCells == 0) {
		return false;
	}
	for (int i = 0; i < board.WIN_POS.size(); i++) {
		if ((board.board[board.WIN_POS[i][0] - 1] != '.') && 
			(board.board[board.WIN_POS[i][0] - 1] == board.board[board.WIN_POS[i][1] - 1]) &&
			(board.board[board.WIN_POS[i][1] - 1] == board.board[board.WIN_POS[i][2] - 1])) {
			return false;
		}
	}*/
	//return true;
	return board->isPlaying();
	

}
Player* Game::getNextPlayer() {
	return ((curPlayer % 2 == 1) ? p1 : p2);
}

std::string Game::getCurrentBoard() {
	std::stringstream ss("");
	for (int i = 0; i < 9; i++) {
		ss << board->board[i] << ' ';
		if (i % 3 == 2) {
			ss << "\n";
		}
	}
	return ss.str();
}
bool Game::isValid(int pos) {
	return board->isValid(pos);
}
void Game::makeMove(int pos) {
	/*if (curPlayer % 2 == 1) {
		board.makeMove(pos, 'X');
		board.board[pos - 1] = 'X';
	}
	else board.board[pos - 1] = '0';

	curPlayer += 1;
	freeCells -= 1;*/
	board->makeMove(pos - 1, getNextPlayer()->getPiece());
	curPlayer += 1;
	
}

int Game::isWon() {
	for (int i = 0; i < board->WIN_POS.size(); i++) {
		if ((board->board[board->WIN_POS[i][0] - 1] != '.') &&
			(board->board[board->WIN_POS[i][0] - 1] == board->board[board->WIN_POS[i][1] - 1]) &&
			(board->board[board->WIN_POS[i][1] - 1] == board->board[board->WIN_POS[i][2] - 1])) {
			if (board->board[board->WIN_POS[i][0] - 1] == 'X') {
				return 1;
			}
			else {
				return 2;
			}
		}
	}
	return -1;
}