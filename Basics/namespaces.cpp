#include <iostream>

namespace one {
	void print(std::string s) {
		std::cout << '\"' << s << '\"' << '\n';
	}
}

namespace two {
	void print(std::string s) {
		std::cout << '\'' << s << '\'' << '\n';
	}
}

using namespace one;

int main()
{
	using one::print;
	namespace b = two;

	print("hello");
	b::print("hello");
}