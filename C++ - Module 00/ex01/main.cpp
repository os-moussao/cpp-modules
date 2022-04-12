#include "main.hpp"

int main()
{
	PhoneBook data;
	std::string input;
	e_cmd cmd;

	while (1) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::flush;
		if (!std::getline(std::cin, input)) return 1;
		cmd = which(input);
		if (cmd == UNK) {
			std::cerr << "Invalid command!" << std::endl;
			continue ;
		}
		if (cmd == ADD) add(data);
		else if (cmd == SEARCH) search(data);
		else if (cmd == EXIT) return 0;
	}
	return 0;
}
