#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called\n";
	*this = brain;
}

const std::string &Brain::getIdea(int idx) const {
	if (idx < 0 || idx >= 100) {
		std::cerr << "Index out of range\n";
		exit(1);
	}
	return ideas[idx];
}

const Brain &Brain::operator = (const Brain &brain) {
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.getIdea(i);
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called\n";
}