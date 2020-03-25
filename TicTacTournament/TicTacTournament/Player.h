/*
Alena Selezneva
*/


#pragma once
class Player
{
public:
	Player(char p) :piece(p) {}
	virtual ~Player() {}

	virtual int getMove() = 0; // abstract 
	char getPiece() { return piece; };

private:
	char piece;
};
