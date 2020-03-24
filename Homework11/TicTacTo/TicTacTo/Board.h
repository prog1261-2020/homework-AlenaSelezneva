/*
Alena
*/


#include <vector>

#pragma once
class Board
{
public:
	Board();
	int getWinningMove(char piece);
	bool isPlaying();
	void makeMove(int pos, char piece);
	bool isValid(int pos);

	std::vector<char> board;
	
	
	const std::vector<std::vector<int> > WIN_POS = {
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}
	};

	const std::vector<char> PLAYER_PIECES = { 'X', '0' };

private:
	int freeCells;


};

