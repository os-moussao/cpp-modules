#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "./program [complain]\n";
		return 1;
	}

	Harl().complain(std::string(av[1]));
}
