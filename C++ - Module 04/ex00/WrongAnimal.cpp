#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called\n";
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound\n";
}

const std::string &WrongAnimal::getType() const {
	return type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called\n";
}