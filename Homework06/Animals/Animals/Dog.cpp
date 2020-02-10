#include "Dog.h"
#include "Animal.h"
#include <string>
#include <iostream>

Dog::Dog(std::string n):Animal(n, "dog", "Gav") {}

void Dog::speak() const  {
	/*Animal::speak();
	std::cout << " Gav-Gav!\n";*/
	std::cout << getSound() << " " << getSound() << " " << getSound() << "\n";
}

int Dog::walk() {
	return ++walked;
}

void Dog::move() {
	std::cout << "I'm running\n";
}