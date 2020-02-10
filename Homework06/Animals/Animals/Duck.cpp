#include "Duck.h"
#include <iostream>


Duck::Duck(std::string n) :Animal(n, "duck", "Quack"){}

void Duck::speak() const {
	//Animal::speak();
	std::cout << getSound() << " " << getSound() << " " << getSound() << "\n";
}

int Duck::feed() {
	return ++fed;
}

void  Duck::swim() {
	std::cout << "Splash splash splash\n";
}
void Duck::move() {
	std::cout << "I'm flying\n";
}