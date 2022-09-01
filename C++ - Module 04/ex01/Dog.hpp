#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &Dog);
		const Brain &getBrain() const;
		const Dog &operator = (const Dog &dog);
		void makeSound() const;
		~Dog();
};