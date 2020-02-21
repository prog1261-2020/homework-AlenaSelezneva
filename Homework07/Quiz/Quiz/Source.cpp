/*
Alena Selezneva
*/

#include "Question.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {

	std::fstream file;
	file.open("Quiz.txt");

	std::vector<Question*> questions;
	std::stringstream ss("");
	ss << "**********************************************\n" <<
		  "*                    QUIZ                    *\n" <<
		  "**********************************************\n\n";
	
	while (!file.eof()) {
		questions.push_back(new Question(file));
	}

	int points = 0;

	for (int i = 0; i < questions.size(); i++) {
		system("cls");
		std::cout << ss.str();

		std::cout << "Question #" << i + 1 << ": " << questions[i]->question  << "\n";
		for (int j = 0; j < questions[i]->answers.size(); j++) {
			std::cout << j + 1 << ": " << questions[i]->answers[j] << "\n";
		}
		int userAnswer;
		std::cin >> userAnswer;
		if (userAnswer - 1 == questions[i]->rightIndex) {
			std::cout << "RIGHT\n";
			++points;
		}
		else {
			std::cout << "WRONG\n";
		}
		system("pause");
	}

	system("cls");
	std::cout << "\n\n     GAME OVER\n\n" <<
		"Your score is " << points << "/" << questions.size() << "\n\n";

}



