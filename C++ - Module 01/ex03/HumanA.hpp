#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon      &weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void attack();
};