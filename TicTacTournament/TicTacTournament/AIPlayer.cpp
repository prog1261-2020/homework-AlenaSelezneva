#include "AIPlayer.h"
#include <vector>
#include <map>
//#include <>


AIPlayer::AIPlayer(char p, Board* b): Player(p) {
	board = b;
}


int AIPlayer::getMove() {
	const std::vector<std::vector<int> > WIN_POS = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, 
		{1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}
	};
	const std::vector<char> PLAYER_PIECES = { 'X', '0' };
	const std::vector<int> corners = { 0, 2, 6, 8 };
	const std::vector<int> sides = {1, 3, 5, 7};
	std::map<int, int> oppositeCorners = { {0, 8}, {2, 6}, {8, 0}, {6, 2} };
	std::map<int, std::pair<int, int> > adjoiningCorners = { {0, {2, 6}}, {2, {0, 8}}, {6, {0, 8}}, {8, {2, 6}} };


	std::vector<char> field = board->getBoard();

	//int pos = -1;

	//
	for (int i = 0; i < WIN_POS.size(); i++) {
		int combo = 0;
		for (int j = 0; j < 3; j++) {
			if (field[WIN_POS[i][j]] == getPiece())
				++combo;
		}
		if (combo == 2) {
			for (int j = 0; j < 3; j++) {
				if (field[WIN_POS[i][j]] == ' ')
					return WIN_POS[i][j];
			}
		}
	}

	char otherPiece = (getPiece() == 'X' ? '0' : 'X');

	for (int i = 0; i < WIN_POS.size(); i++) {
		int combo = 0;
		for (int j = 0; j < 3; j++) {
			if (field[WIN_POS[i][j]] == otherPiece)
				++combo;
		}
		if (combo == 2) {
			for (int j = 0; j < 3; j++) {
				if (field[WIN_POS[i][j]] == ' ')
					return WIN_POS[i][j];
			}
		}
	}

	// Other strategies (no winning position found)
	int freeCells = 0;
	for (int i = 0; i < 9; i++) {
		if (field[i] == ' ') {
			freeCells += 1;
		}
	}

	//finding free corners
	std::vector<int> freeCorners;
	if (field[0] == ' ') {
		freeCorners.push_back(0);
	}
	if (field[2] == ' ') {
		freeCorners.push_back(2);
	}
	if (field[6] == ' ') {
		freeCorners.push_back(6);
	}
	if (field[8] == ' ') {
		freeCorners.push_back(8);
	}

	// doing stuff depending on turn
	switch (freeCells)
	{
	case 9:
		return freeCorners[rand() % 4];
		break;
	case 8:
		if (freeCorners.size() < 4) {
			return 4;
		}
		else {
			return freeCorners[rand() % 4];
		}
		break;
	case 7:
		if (freeCorners.size() == 3) {
			int myCorner = 0;
			for (int i = 0; i < 4; i++) {
				if (field[corners[i]] == getPiece()) {
					myCorner = corners[i];
				}
			}
			if (field[4] == ' ') {
				return 4;
			}
			else {
				return oppositeCorners[myCorner];
			}
		}
		else if (freeCorners.size() == 2) {
			return freeCorners[rand() % 2];
		}
		break;
	case 6:
		if (freeCorners.size() == 2 && field[4] != ' ') {
			return sides[rand() % 4];
		}
		else {
			if (field[4] == ' ') {
				return 4;
			}
			else {
				return freeCorners[rand() % freeCorners.size()];
			}
		}
		break;
	case 5:
		if (freeCorners.size() > 0) {
			return freeCorners[rand() % freeCorners.size()];
		}
		else if (field[4] == ' ') {
			return 4;
		}else {
			int pos = -1;
			while (!board->isValidMove(pos)) {
				pos = rand() % 9;
			}
			return pos;
		}
		break;
	default:
		int pos = -1;
		while (!board->isValidMove(pos)) {
			pos = rand() % 9;
		}
		return pos;
		break;
	}


	int pos = -1;
	while (!board->isValidMove(pos)) {
		pos = rand() % 9;
	}
	return pos;
}