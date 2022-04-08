#include <iostream>

class Animal
{
	private:
		int type;
	public:
		Animal(){this->type = 0;}
		virtual ~Animal(){};
		virtual void makeSound() const = 0;
		int get(){
			return this->type;
		}
};


class Dog: public Animal
{
	public:
		void makeSound() const override
		{
			std::cout << "Bark Bark !" << std::endl;
		}
};

class Cat: public Animal
{
	public:
		void makeSound() const override
		{
			std::cout << "Moew Moew!" << std::endl;
		}
};


int main()
{
	// Animal dog;
	Animal *dog = new Dog();
	dog->makeSound();
	Animal *cat = new Cat();
	cat->makeSound();

	delete dog;
	delete cat;
}
