#include "main.hpp"

e_cmd which(std::string &inp) {
	if (inp == "ADD") return ADD;
	if (inp == "SEARCH") return SEARCH;
	if (inp == "EXIT") return EXIT;
	return UNK;
}

void getdata(std::string prompt, Contact &person, e_type type)
{
	std::string inp;

	prompt += ": ";
	while (1) {
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, inp)) exit(1);
		if (inp == "" || inp.find_first_not_of(" \t\n\v\f\r") == std::string::npos) continue ;
		break ;
	}
	if (type == FNAME) person.setFirstName(inp);
	else if (type == LNAME) person.setLastName(inp);
	else if (type == NNAME) person.setNickname(inp);
	else if (type == PHONE) person.setPhoneNumber(inp);
	else if (type == DARSEC) person.setDarkestSec(inp);
}

void add(PhoneBook &data) {
	Contact person;
	std::string inp;

	getdata("First name", person, FNAME);
	getdata("Last name", person, LNAME);
	getdata("Nickname", person, NNAME);
	getdata("Phone number", person, PHONE);
	getdata("Darkest secret", person, DARSEC);
	data.addContact(person);
}

void search(PhoneBook &data) {
	if (data.display())
	{
		int index;
		std::string inp;
		
		std::cout << "Which index: " << std::flush;

		if (!std::getline(std::cin, inp)) exit(1);

		for (int i = 0; i < (int)inp.length(); i++) {
			if (!isdigit(inp[i])) {
				std::cerr << "Invalid input!" << std::endl;
				return ;
			}
		}

		index = stoi(inp);
		if (index <= 0 || index > data.size()) {
			std::cerr << "Error! The index given is out of range!" << std::endl;
			return ;
		}
		data.display(--index);
	}
	else {
		std::cout << "Empthy Phonebook!" << std::endl;
	}
}