#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called\n";
	type = "Dog";
	brain = new Brain();
	*this = dog;
}

const Brain &Dog::getBrain() const {
	return *brain;
}

const Dog & Dog::operator = (const Dog &dog) {
	return *brain = dog.getBrain(), *this;
}

void Dog::makeSound() const {
	std::cout << "Bark... Bark... Bark...\n";
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called\n";
}