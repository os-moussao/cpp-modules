#include "FragTrap.hpp"

int main()
{
	FragTrap a("Bob"), b("Tom");

	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl;
	b.attack(a.getName());

	std::cout << std::endl;
	b.beRepaired(10);

	std::cout << std::endl;
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << a.getName() << "'s remaining hit points: " << a.getHitPoints() << std::endl;
	std::cout << b.getName() << "'s remaining hit points: " << b.getHitPoints() << std::endl;
	std::cout << std::endl;
}