#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called\n";
	type = "WrongCat";
}

void WrongCat::makeSound() const {
	std::cout << "Meow... Meow... Meow...\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}