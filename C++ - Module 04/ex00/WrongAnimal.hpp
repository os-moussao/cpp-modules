#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		void makeSound() const;
		const std::string &getType() const;
		virtual ~WrongAnimal();
};