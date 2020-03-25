#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
class Board
{
public:
	Board();
	std::vector<char> getBoard();
	void reset();
	bool isFull() const;
	bool isValidMove(int move) const;
	bool isWinner(char playerPiece) const;
	std::string getBoardPlaces() const;
	std::string getCurrentBoard() const;
	void makeMove(char playerPiece, int move);


	static const int NUM_WINNING_COMBOS = 8;								//number of winning combos
	static const int NUM_IN_COMBO = 3;										//number of items in combo
	static const int WINNING_COMBOS[NUM_WINNING_COMBOS][NUM_IN_COMBO];		//matrix of winning combos

private:
	bool checkCombo(int combo, char piece) const;
	static const int NUM_SQUARES = 9;										//total number of squares
	static const char EMPTY = ' ';											//empty strings

	std::vector<char> board;												//'X', 'O', or ' '
};