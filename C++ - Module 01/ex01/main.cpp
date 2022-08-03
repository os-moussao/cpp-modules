#include "Zombie.hpp"
#include "zombieHorde.hpp"

#define SZ 8

int main() {
	Zombie *arr = zombieHorde(SZ, "FooBar");

	for (int i = 0; i < SZ; i++) {
		arr[i].annouce();
	}
	
	delete[] arr;
}