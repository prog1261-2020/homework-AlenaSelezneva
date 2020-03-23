/*
Alena
*/


#pragma once
class Player
{
public:
	//char getPiece();
	virtual int makeMove();
	virtual int getMove();
	virtual ~Player();
	char getPiece();

protected:
	int move{ -1 };
	char piece;

};

