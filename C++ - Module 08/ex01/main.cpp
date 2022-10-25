#include "Span.hpp"

int main()
{
	try {
		Span sp = Span((unsigned int)(1e5 + 6));
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(12);
		std::vector<int> vec;
		for (int i = 100, j = 0; j < (int)(1e5); i+=100, j++) {
			vec.push_back(i);
		}
		sp.insert(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(10);
	}
	
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Span sp(10);

		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Span sp(10);

		for (int i = 10; i >= 1; i--) {
			sp.addNumber(i);
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}