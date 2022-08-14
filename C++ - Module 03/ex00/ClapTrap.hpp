#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int hitPoints, energyPoints, attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &clap);
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		void setHitPoints(int x);
		void setEnergyPoints(int x);
		void setAttackDamage(int x);
		void operator = (const ClapTrap &clap);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};