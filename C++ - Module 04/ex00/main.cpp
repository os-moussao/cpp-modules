#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Test 1:" << std::endl;
	{	const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		delete meta;
		delete i;
		delete j;
	}

	std::cout << "\nTest 2:" << std::endl;
	{
		const WrongAnimal* i = new WrongCat();

		std::cout << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;
		i->makeSound();

		std::cout << std::endl;
		delete i;
	}
}