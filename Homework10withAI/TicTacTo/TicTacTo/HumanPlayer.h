
#include "Player.h"

#pragma once
class HumanPlayer: public Player
{
public:
	HumanPlayer(char piece);
	int makeMove() override;
	int getMove() override;
	~HumanPlayer() override;

};

