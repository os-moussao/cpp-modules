#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &cat);
		const Brain &getBrain() const;
		const Cat &operator = (const Cat &cat);
		void makeSound() const;
		~Cat();
};