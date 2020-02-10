#pragma once
#include "Animal.h"
class Duck : public Animal{
public:
	Duck(std::string n);
	int feed();
	void speak() const ;
	void swim();
	void move();

private:
	int fed = 0;

};

