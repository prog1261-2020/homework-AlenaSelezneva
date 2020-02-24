/*
Alena Selezneva
*/


#include "Question.h"
#include <sstream>

Question::Question(std::fstream& file) {
	char buffer[512];
	while (!((buffer[0] >= 'A' && buffer[0] <= 'Z') || (buffer[0] >= 'a' && buffer[0] <= 'z'))) {
		file.getline(buffer, 512);
	}
	question = buffer;

	file.getline(buffer, 512);
	while (!(buffer[0] >= '0' && buffer[0] <= '9')) {
		answers.push_back(buffer);
		file.getline(buffer, 512);
	}
	std::stringstream ss(buffer) ;
	ss >> rightIndex;

}