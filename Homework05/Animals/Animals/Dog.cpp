#include "Dog.h"
#include "Animal.h"
#include <string>
#include <iostream>

Dog::Dog(std::string n):Animal(n, "dog", "Gav") {}

void Dog::speak() {
	Animal::speak();
	std::cout << " Gav-Gav!\n";
}