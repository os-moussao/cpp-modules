#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

template <class T>
class MutantStack: public std::stack<T, std::deque<T> > {
	public:
		typedef typename std::deque<T>::const_iterator iterator;
		iterator begin() const { return this->c.begin(); }
		iterator end() const { return this->c.end(); }
};