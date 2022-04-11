#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->N = this->index = 0;
}

int PhoneBook::size() const {
	return this->N;
}

void log(const std::string s, bool last) {
	if (s.length() > 10) {
		std::cout << s.substr(0, 9) << '.';
	}
	else {
		std::cout << std::setw(10) << s;
	}
	if (last) {
		std::cout << std::endl;
	}
	else {
		std::cout << '|';
	}
}

bool PhoneBook::display() const {
	if (this->N)
		std::cout << "Index     |First Name|Last Name |Nickname" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << std::setw(10) << i + 1 << '|';
		log(arr[i].getFirstName(), 0);
		log(arr[i].getLastName(), 0);
		log(arr[i].getNickname(), 1);
	}
	return !!this->N;
}

void PhoneBook::display(int ind) const {
	Contact pers;

	pers = arr[ind];
	std::cout << "First name: " << pers.getFirstName() << std::endl;
	std::cout << "Last name: " << pers.getLastName() << std::endl;
	std::cout << "Nickname: " << pers.getNickname() << std::endl;
	std::cout << "Phone number: " << pers.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << pers.getDarkestSec() << std::endl;
}

void PhoneBook::addContact(Contact person) {
	N += N < MAX? 1: 0;
	this->arr[index] = person;
	index = (index + 1) % MAX;
}
