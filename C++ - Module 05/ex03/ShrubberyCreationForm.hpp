#pragma once

#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	// private:
		// const std::string target;
	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		virtual void action() const;
};