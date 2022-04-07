#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < ac; i++) {
		std::string str = av[i];
		// std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		// std::for_each(str.begin(), str.end(), func); std::cout << str;
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			std::cout << (char)toupper(*it);
	}
	std::cout << std::endl;
}
