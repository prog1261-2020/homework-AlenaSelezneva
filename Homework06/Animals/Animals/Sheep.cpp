#include "Sheep.h"
#include <iostream>
#include <string>

Sheep::Sheep(std::string n): Animal(n, "sheep", "beeee") {}

void Sheep::speak()const {
	std::cout << "beeee beeee beeee\n";
}
void Sheep::move() {
	std::cout << "I'm walking\n";
}