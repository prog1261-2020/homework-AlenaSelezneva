/*
Alena Selezneva
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::string fixString(std::string word) {
	if (word.size() == 0) {
		return "";
	}

	while (word.size() > 0) {
		if (!((word[word.size() - 1] >= 'a' && word[word.size() - 1] <= 'z') ||
			(word[word.size() - 1] >= 'A' && word[word.size() - 1] <= 'Z'))) {
			word.pop_back();
		}
		else {
			break;
		}
	}

	while (word.size() > 0) {
		if (!((word[0] >= 'a' && word[0] <= 'z') ||
			(word[0] >= 'A' && word[0] <= 'Z'))) {
			word.erase(0, 1);
		}
		else {
			break;
		}
	}

	if (word.size() == 0) {
		return "";
	}

	for (int i = 0; i < word.size(); i++) {
		if (((word[word.size() - 1] >= 'a' && word[word.size() - 1] <= 'z') ||
			(word[word.size() - 1] >= 'A' && word[word.size() - 1] <= 'Z'))) {
			word[i] = std::tolower(word[i]);
		}

	}
	return word;
}

int main() {
	std::fstream file;
	file.open("fox.txt", std::ios::in);

	if (!file) {
		std::cout << "File is not open!";
		return 0;
	}

	std::map<std::string, int> m;

	std::string word;
	while (!file.eof()) {
		file >> word;
		word = fixString(word);
		if (word == "") continue;
		m[word] += 1;
	}

	for (auto p : m) {
		if (p.first == "") continue;
		std::cout << p.first << " : " << p.second << "\n";
	}

	file.close();

}