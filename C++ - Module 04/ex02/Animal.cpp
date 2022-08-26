#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called\n";
}

const std::string &Animal::getType() const {
	return type;
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n";
}