#include "Intern.hpp"

// "robotomy request", "presidential request", "shrubbery request" 
int main()
{
	Intern intern;

	std::cout << std::endl;
	try {
		Bureaucrat b("B1", 1);
		Form *s = intern.makeForm("shrubbery request", "F1");
		if (!s) {
			return 1;
		}
		b.signForm(*s);
		s->execute(b);
		delete s;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try {
		Bureaucrat b("B2", 1);
		Form *s = intern.makeForm("robotomy request", "F2");
		if (!s) {
			return 1;
		}
		b.signForm(*s);
		s->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try {
		Bureaucrat b("B3", 1);
		Form *s = intern.makeForm("presidential request", "F3");
		if (!s) {
			return 1;
		}
		b.signForm(*s);
		s->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try {
		Form *badForm = intern.makeForm("foobar", "foobar");
		if (!badForm) {
			return 1;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}