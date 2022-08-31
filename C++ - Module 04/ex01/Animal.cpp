#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called\n";
}

void Animal::makeSound() const {
	std::cout << "Animal Sound\n";
}

const std::string &Animal::getType() const {
	return type;
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n";
}