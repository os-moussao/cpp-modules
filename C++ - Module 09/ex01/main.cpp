#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        return std::cerr << "usage: ./RPN <inverted polish mathematical expression>\n", 1;
    }

    try {
        std::cout << calc(av[1]) << '\n';
    }

	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}