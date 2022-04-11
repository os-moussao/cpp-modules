#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string const &first_name, std::string const &last_name,
				 std::string const &nickname, std::string const &phone_number,
				 std::string const &darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const {
	return this->_first_name;
}

std::string Contact::getLastName() const {
	return this->_last_name;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phone_number;
}

std::string Contact::getDarkestSec() const {
	return this->_darkest_secret;
}

void Contact::setFirstName(const std::string s) {
	this->_first_name = s;
}

void Contact::setLastName(const std::string s) {
	this->_last_name = s;
}

void Contact::setNickname(const std::string s) {
	this->_nickname = s;
}

void Contact::setPhoneNumber(const std::string s) {
	this->_phone_number = s;
}

void Contact::setDarkestSec(const std::string s) {
	this->_darkest_secret = s;
}
