#pragma once 

#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		Contact();
		Contact(std::string const &, std::string const &, std::string const &, std::string const &, std::string const &);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSec() const;
		void		setFirstName(const std::string s);
		void		setLastName(const std::string s);
		void		setNickname(const std::string s);
		void		setPhoneNumber(const std::string s);
		void		setDarkestSec(const std::string s);
};