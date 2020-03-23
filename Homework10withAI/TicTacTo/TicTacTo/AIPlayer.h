
#include "Player.h"
#include "Game.h"
#include "Board.h"

#pragma once
class AIPlayer : public Player
{
public:
	AIPlayer(char piece, Board* board);
	int makeMove();
	int getMove();

private:
	Board* board;
};

