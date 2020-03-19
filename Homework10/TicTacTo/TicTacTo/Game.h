#pragma once

#include <vector>
#include "Player.h"
#include <string>
//#include <memory>

class Game
{
public:
	Game();
	bool isPlaying();
	Player* getNextPlayer();
	std::string getCurrentBoard();
	bool isValid(int pos);
	void makeMove(int pos);
	int isWon();
private:
	Player* p1;
	Player* p2;
	int curPlayer;
	std::vector<char> board;
	std::vector<std::vector<int> > winPos;
	int freeCells;
};

