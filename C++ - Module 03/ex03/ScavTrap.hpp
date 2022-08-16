#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		virtual void attack(const std::string& target);
		void guardGate();
		virtual ~ScavTrap();
};