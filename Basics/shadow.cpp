#include <iostream>

// detect by -Wshadow
int main() {
	for (int i = 0; i < 10; i++) {
		std::cout << "from loop1: " << i << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << "from loop2: " << i << std::endl;
		}
	}
}