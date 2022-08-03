#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug() {
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::info() {
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning() {
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error() {
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level) {
	
	std::string cmp[4] = {
		"debug", "info", "warning", "error"
	};

	for (int i = 0; i < (int)level.length(); i++)
		level[i] = tolower(level[i]);

	int i;
	for (i = 0; i < 4 && cmp[i] != level; i++);

	switch (i)
	{
		case (0):
			(this->debug)();
			i++;
		case (1):
			(this->info)();
			i++;
		case (2):
			(this->warning)();
			i++;
		case (3):
			(this->error)();
			i++;
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}