#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		void makeSound() const;
		~Dog();
};