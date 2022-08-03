#include "Zombie.hpp"

Zombie::Zombie () {}
Zombie::Zombie (std::string name): name(name) {}

Zombie::~Zombie () {
	std::cout << name << " was destroyed\n";
}

void Zombie::annouce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
	this->name = name;
}