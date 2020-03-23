#include "AIPlayer.h"

#include <thread>         
#include <chrono>


AIPlayer::AIPlayer(char piece, Board* board) {
	this->piece = piece;
	this->board = board;
}
int AIPlayer::makeMove() {
	int pos = board->getWinningMove(piece);
	if (pos == -1) {
		char otherPiece = piece;
		for (int i = 0; i < board->PLAYER_PIECES.size(); i++) {
			if (piece != board->PLAYER_PIECES[i]) {
				otherPiece = board->PLAYER_PIECES[i];
			}
		}
		pos = board->getWinningMove(otherPiece);
		if (pos == -1) {
			while (!board->isValid(pos)) {
				pos = rand() % 9 + 1;
			}
		}
	}
	move = pos;
	return move;
}
int AIPlayer::getMove() {
	//_sleep(1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	return move;
}