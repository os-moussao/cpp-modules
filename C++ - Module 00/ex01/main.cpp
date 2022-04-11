#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

enum e_cmd {
	UNK,
	ADD,
	SEARCH,
	EXIT
};

enum e_type {
	FNAME,
	LNAME,
	NNAME,
	PHONE,
	DARSEC
};

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
		if (inp == "") continue ;
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
		std::cout << "Which index: " << std::flush;
		int index;
		if (!(std::cin >> index)) exit(1);
		if (index <= 0 || index > data.size()) {
			std::cout << "Error! The index given is out of range!" << std::endl;
			return ;
		}
		data.display(--index);
	}
	else {
		std::cout << "Empthy Phonebook!" << std::endl;
	}
}

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
			std::cout << "Invalid command!" << std::endl;
			continue ;
		}
		if (cmd == ADD) add(data);
		else if (cmd == SEARCH) search(data);
		else if (cmd == EXIT) return 0;
	}
	return 0;
}
