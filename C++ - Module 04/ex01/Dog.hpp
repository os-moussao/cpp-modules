#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		void makeSound() const;
		~Dog();
};