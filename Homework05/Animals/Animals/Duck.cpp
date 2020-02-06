#include "Duck.h"


Duck::Duck(std::string n) :Animal(n, "duck", "Quack"){}

void Duck::speak() {
	Animal::speak();
}