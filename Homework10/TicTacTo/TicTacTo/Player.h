#pragma once
class Player
{
public:
	//char getPiece();
	virtual int makeMove();
	virtual int getMove() const;

protected:
	int move{ -1 };

};

