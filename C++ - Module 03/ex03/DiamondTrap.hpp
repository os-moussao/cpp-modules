#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		void setHitPoints(int x);
		void setEnergyPoints(int x);
		void setAttackDamage(int x);
		void attack(const std::string& target);
		void whoAmI();
		~DiamondTrap();
};