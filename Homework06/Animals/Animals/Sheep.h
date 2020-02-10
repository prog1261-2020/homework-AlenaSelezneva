#pragma once
#include "Animal.h"


class Sheep : public Animal
{
public:
	Sheep(std::string n);

	void speak()const;
	void move();
};

