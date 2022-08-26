#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
}

void Dog::makeSound() const {
	std::cout << "Bark... Bark... Bark...\n";
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
}