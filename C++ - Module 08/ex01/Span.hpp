#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

class Span
{
	private:
		const unsigned int N;
		std::vector<int> a;
		int	_shortestSpan, _longestSpan;
	public:
		typedef std::vector<int>::iterator itt;
		Span(unsigned int N);
		~Span();
		void addNumber(int x);
		int shortestSpan() const;
		int longestSpan() const;
		void insert(itt begin, itt end);
		class FullSpan: public std::exception {
			virtual const char * what(void) const throw();
		};
		class NoSpan: public std::exception {
			virtual const char * what(void) const throw();
		};
};