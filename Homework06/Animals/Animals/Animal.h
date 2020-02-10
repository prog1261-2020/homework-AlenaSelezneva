#include <string>
#include <iostream>
#pragma once
class Animal
{
private:
	Animal();
protected:
	Animal(const std::string& name, const std::string& type, const std::string& sound);
public:
	//Animal() = delete;
	const std::string& getName() const;
	const std::string& getType() const;
	const std::string& getSound() const;

	virtual void speak() const;
	virtual void move() = 0;
	//virtual void move() = 0;	//abstract

protected:
	std::string name;
	std::string type;
	std::string sound;
};

