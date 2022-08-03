#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): name(name) {
	this->weapon = NULL;
}

void HumanB::setWeapon (Weapon &weapon) { this->weapon = &weapon; }

void HumanB::attack() {
	std::cout << name << " attacks with their " << \
	(weapon != NULL? weapon->getType(): "NULL") << '\n';
}
