#pragma once

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


e_cmd which(std::string &inp);
void getdata(std::string prompt, Contact &person, e_type type);
void add(PhoneBook &data);
void search(PhoneBook &data);