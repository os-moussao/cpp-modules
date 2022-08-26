#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called\n";
	type = "Cat";
}

void Cat::makeSound() const {
	std::cout << "Meow... Meow... Meow...\n";
}

Cat::~Cat() {
	std::cout << "Cat destructor called\n";
}