#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual void makeSound() const;
		const std::string &getType() const;
		virtual ~Animal();
};