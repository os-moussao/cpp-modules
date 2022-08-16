#include "ClapTrap.hpp"

int min(int a, int b) { return a < b? a: b; }

ClapTrap::ClapTrap()
	: hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = clap;
}

std::string ClapTrap::getName() const {
	return name;
}

int ClapTrap::getHitPoints() const {
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::setHitPoints(int x) {
	hitPoints = x;
}

void ClapTrap::setEnergyPoints(int x) {
	energyPoints = x;
}

void ClapTrap::setAttackDamage(int x) {
	attackDamage = x;
}

void ClapTrap::operator = (const ClapTrap &clap) {
	std::cout << "Assignment operator called\n";
	name = clap.getName();
	hitPoints = clap.getHitPoints();
	attackDamage = clap.getAttackDamage();
	energyPoints = clap.getEnergyPoints();
}

void ClapTrap::attack(const std::string& target) {
	if (!energyPoints || !hitPoints) {
		std::cout << "ClapTrap " << name << " can't attack " << target << "!\n";
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " \
	<< target << " causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " gets " << amount << " amount of damage\n";
	hitPoints -= min(amount, hitPoints);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!energyPoints) {
		std::cout << "ClapTrap " << name << " can't repaire itself due to lack of energy!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " repaires itself with additional " << amount << " amount of hit points\n";
	energyPoints--;
	hitPoints += amount;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called\n";
}