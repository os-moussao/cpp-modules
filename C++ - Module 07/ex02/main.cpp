#include <iostream>
#include <string>
#include "Array.hpp"



int main( void ) {
	try {
		Array<int> a(10);
		for (size_t i = 0; i < a.size(); i++) {
			a[i] = i+1;
			std::cout << a[i] << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Array<std::string> a(10);
		for (size_t i = 0; i < a.size(); i++) {
			a[i] = "string_" + std::to_string(i+1);
			std::cout << a[i] << std::endl;
		}
		std::cout << std::endl;
		Array<std::string> b(a);
		for (size_t i = 0; i< b.size(); i++) {
			std::cout << b[i] << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}