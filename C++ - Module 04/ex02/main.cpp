#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Cat* i = new Cat();
	const Dog* j = new Dog();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;
	delete i;
	delete j;
}