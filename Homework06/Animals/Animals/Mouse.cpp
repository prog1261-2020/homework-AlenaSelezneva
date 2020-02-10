#include "Mouse.h"
#include <string>

Mouse::Mouse(std::string n) : Animal(n, "mouse", "pi") {}

void Mouse::speak()const {
	std::cout << "pi pi pi\n";
}
void Mouse::move() {
	std::cout << "I'm crawling\n";
}