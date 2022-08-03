#pragma once

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(const std::string &type);
		Weapon(const Weapon &weapon);
		const std::string &getType(void) const;
		void setType(const std::string &type);
};