#include "Intern.hpp"

typedef Form *(*fp) (const std::string &);

const std::string names[3] = {
	"robotomy request", "presidential request", "shrubbery request" 
};

Form *new_shrubery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

Form *new_presidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

Form *new_robotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

fp a[3] = {
	new_robotomy, new_presidential, new_shrubery
};

Intern::Intern() {
	std::cout << "Intern constructor called\n";
}

Intern::~Intern() {
	std::cout << "Intern destructor called\n";
}

Form *Intern::makeForm(const std::string &form, const std::string &target) {
	int index = 0;
	for (; index < 3; index++) {
		if (form==names[index])
			break ;
	}
	if (index == 3) {
		std::cerr << "Intern: " << form << ": bad form request!\n";
		return NULL;
	}
	return a[index](target);
}