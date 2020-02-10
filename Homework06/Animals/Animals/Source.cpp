/*
Alena Selezneva
*/
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Duck.h"
#include "Mouse.h"
#include "Sheep.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {

	/*Cat cat("Sabrina");
	Dog dog("Fido");
	Duck duck("Donald J Duck");*/

	//Animal a = Animal();

	//std::cout << "\n\n";
	//cat.speak();
	//dog.speak();
	//duck.speak();

	//std::cout << "\n\n";

	//std::cout << cat.getType() << " has been petted " << cat.pet() << " times\n\n";
	//std::cout << dog.getType() << " has been petted " << dog.walk() << " times\n\n";
	//std::cout << duck.getType() << " has been petted " << duck.feed() << " times\n\n";


	/*Animal* c = new Cat("Fluffy");
	Animal* d = new Dog("Butch");

	c->speak();
	d->speak();*/



	/******************* POLYMORPHISM **********************/

	std::vector<std::unique_ptr<Animal> > zoo;
	zoo.push_back(std::make_unique<Cat>("Fluffy"));
	zoo.push_back(std::make_unique<Dog>("Fido"));
	zoo.push_back(std::make_unique<Duck>("Daffy"));
	zoo.push_back(std::make_unique<Mouse>("Stuart"));
	zoo.push_back(std::make_unique<Sheep>("Dolly"));

	for (auto& a : zoo) {
		a->speak();
		a->move();
		//Downcast - don't do this!
		//((Duck*)a.get())->swim();
	}

	/*Duck* d = new Duck("Daffy-2");
	d->swim();*/


}