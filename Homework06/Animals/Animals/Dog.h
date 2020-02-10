#pragma once
#include "Animal.h"
#include <string>
class Dog : public Animal
{
public:
	Dog(std::string n);
	void speak() const ;
	int walk();
	void move();

private:
	int walked = 0;
};

