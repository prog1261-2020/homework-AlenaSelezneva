/*
Alena Selezneva
*/


#pragma once

#include <vector>
#include "Player.h"
#include <string>
#include "Board.h"
//#include <memory>

class Game
{
public:

	void play();

	//Game(int humans);
	Game(Player* one, Player* two, Board* board);
	bool isPlaying();
	Player* getNextPlayer();
	std::string getCurrentBoard();
	bool isValid(int pos);
	void makeMove(int pos);
	char isWon();
private:
	Player* p1;
	Player* p2;
	int curPlayer;
	//std::vector<char> board;
	//std::vector<std::vector<int> > winPos;
	//int freeCells;
	Board* board;

};

