#pragma once

#include "Contact.hpp"
#include <iomanip>

#define MAX 8

class PhoneBook
{
	private:
		int     N;
		int     index;
		Contact arr[MAX];
	public:
		PhoneBook();
		int  size() const;
		bool display() const;
		void display(int ind) const;
		void addContact(Contact person);
};