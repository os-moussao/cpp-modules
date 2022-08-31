#pragma once

#include <iostream>
#include <cstdlib>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		const std::string &getIdea(int idx) const;
		const Brain &operator = (const Brain &brain);
		~Brain();
};