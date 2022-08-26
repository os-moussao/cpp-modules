#pragma once

#include <iostream>
#include <string>

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