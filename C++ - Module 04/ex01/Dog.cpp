#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
	brain = new Brain();
}

void Dog::makeSound() const {
	std::cout << "Bark... Bark... Bark...\n";
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called\n";
}