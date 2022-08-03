#include "Zombie.hpp"
#include "newZombie.hpp"
#include "randomChump.hpp"

int main() {
	Zombie *omar = newZombie("omar");
	
	omar->annouce();
	std::cout << '\n';
	
	randomChump("omoussao");
	std::cout << '\n';
	
	randomChump("sabani");
	std::cout << '\n';
	
	delete omar;
}