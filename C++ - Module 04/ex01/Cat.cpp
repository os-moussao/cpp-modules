#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called\n";
	type = "Cat";
	brain = new Brain();
	*this = cat;
}

const Brain &Cat::getBrain() const {
	return *brain;
}

const Cat & Cat::operator = (const Cat &cat) {
	return *brain = cat.getBrain(), *this;
}

void Cat::makeSound() const {
	std::cout << "Meow... Meow... Meow...\n";
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called\n";
}