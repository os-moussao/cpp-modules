#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap Name constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << ": Heyy give me a high five !\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called\n";
}