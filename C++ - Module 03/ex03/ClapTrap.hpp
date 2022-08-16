#pragma once

#include <iostream>
#include <string>

int min(int, int);

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
		virtual int getHitPoints() const;
		virtual int getEnergyPoints() const;
		virtual int getAttackDamage() const;
		virtual void setHitPoints(int x);
		virtual void setEnergyPoints(int x);
		virtual void setAttackDamage(int x);
		void operator = (const ClapTrap &clap);
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		virtual ~ClapTrap();
};