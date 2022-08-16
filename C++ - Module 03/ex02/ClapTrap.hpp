#pragma once

#include <iostream>
#include <string>

int min(int a, int b);

class ClapTrap
{
	protected:
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
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		virtual ~ClapTrap();
};