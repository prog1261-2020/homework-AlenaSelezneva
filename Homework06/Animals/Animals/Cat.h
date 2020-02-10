#pragma once
#include "Animal.h"
#include <string>

class Cat : public Animal{
public: 
	Cat(std::string n);

	void speak()const ;
	int pet();
	void move();

private:
	int petted = 0;
};

