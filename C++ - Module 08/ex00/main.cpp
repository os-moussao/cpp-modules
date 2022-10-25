#include "easyfind.hpp"

int main( void ) {
	std::string s = "asdfghjkl";
	std::vector<int> vec;
	for (int i = 0; i< 100; i++)
		vec.push_back(i+1);

	int pos;
	if ((pos = easyfind(vec, 100)) == -1) {
		std::cerr << "can't find element" << std::endl;
	} else {
		std::cout << pos << std::endl;
	}
	if ((pos = easyfind(s, (int)'a')) == -1) {
		std::cerr << "can't find element" << std::endl;
	} else {
		std::cout << pos << std::endl;
	}
	if ((pos = easyfind(vec, 101)) == -1) {
		std::cerr << "can't find element" << std::endl;
	} else {
		std::cout << pos << std::endl;
	}
	if ((pos = easyfind(s, (int)'z')) == -1) {
		std::cerr << "can't find element" << std::endl;
	} else {
		std::cout << pos << std::endl;
	}
}