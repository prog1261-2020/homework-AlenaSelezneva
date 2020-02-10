#pragma once
#include "Animal.h"
class Mouse : public Animal
{
public:
	Mouse(std::string n);

	void speak()const;
	void move();
};

