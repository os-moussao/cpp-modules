#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called\n";
	energyPoints = 50;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap name constructor called\n";
	this->name = name;
	energyPoints = 50;
}

int DiamondTrap::getHitPoints() const {
	return FragTrap::hitPoints;
}

int DiamondTrap::getEnergyPoints() const {
	return ScavTrap::energyPoints;
}

int DiamondTrap::getAttackDamage() const {
	return FragTrap::attackDamage;
}

void DiamondTrap::setHitPoints(int x) {
	FragTrap::hitPoints = x;
}

void DiamondTrap::setEnergyPoints(int x) {
	ScavTrap::energyPoints = x;
}

void DiamondTrap::setAttackDamage(int x) {
	FragTrap::attackDamage = x;
}

void DiamondTrap::attack(const std::string& target) {
	return ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << name << " also known as " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called\n";
}