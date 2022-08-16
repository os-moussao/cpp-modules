#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("Pablo");

	std::cout << std::endl;
	a.whoAmI();
	std::cout << a.getHitPoints() << " " << a.getEnergyPoints() << " " << a.getAttackDamage() << std::endl;

	std::cout << std::endl;
	ClapTrap	b("Tom"), c("Bob");

	std::cout << std::endl;
	a.attack("ALL CLAPTRAPS");
	b.takeDamage(a.getAttackDamage());
	c.takeDamage(a.getAttackDamage());

	std::cout << std::endl;
	b.attack(a.getName());
	c.attack(a.getName());

	std::cout << std::endl;
	return 0;
}