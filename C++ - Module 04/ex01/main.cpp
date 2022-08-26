#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define SZ 8

int main()
{
	Animal *animals[SZ];

	for (int i = 0; i < SZ; i++) {
		if (i < SZ/2) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}

	std::cout << std::endl;
	for (int i = 0; i < SZ; i++) {
		animals[i]->makeSound();
	}

	std::cout << std::endl;
	for (int i = 0; i < SZ; i++) {
		delete animals[i];
	}
}