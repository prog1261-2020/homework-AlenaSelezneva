

#pragma once
#include "Player.h"
#include "Board.h"

class AIPlayer : public Player
{
public:
	AIPlayer(char p, Board* b);

	int getMove() override;

private:
	Board* board;
};
