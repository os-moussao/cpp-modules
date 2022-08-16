#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Bob"), b("Tom");

	a.setAttackDamage(5);
	b.setAttackDamage(5);

	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	b.attack(a.getName());

	b.beRepaired(10);

	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;
	std::cout << a.getName() << "'s remaining hit points: " << a.getHitPoints() << std::endl;
	std::cout << b.getName() << "'s remaining hit points: " << b.getHitPoints() << std::endl;
	std::cout << std::endl;
}