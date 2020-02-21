/*
Alena Selezneva
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#pragma once
class Question
{
public:
	Question(std::fstream& file);

	std::string question;
	std::vector<std::string> answers;
	int rightIndex;
};

