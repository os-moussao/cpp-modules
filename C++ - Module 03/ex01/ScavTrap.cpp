#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void ScavTrap::attack(const std::string& target) {
	if (!energyPoints || !hitPoints) {
		std::cout << "ScavTrap " << name << " can't attack " << target << "!\n";
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " \
	<< target << " causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}