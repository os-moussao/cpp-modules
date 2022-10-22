#include <iostream>
#include <string>
#include "iter.hpp"

void print(const int &x) {
	std::cout << std::hex << "0x" << x << std::endl;
}

void print(const std::string &s) {
	std::cout << s << std::endl;
}

void toBinary(int n, std::string &bin) {
	if (!n)
		bin = "0";
	while (n) {
		bin = (n&1? "1": "0") + bin;
		n >>= 1;
	}
	bin = "0b" + bin;
}

int main( void ) {
	int a[10];
	std::string b[10];

	for (int i = 1; i <= 10; i++) {
		a[i-1] = i * 10;
		toBinary(i, b[i-1]);
	}

	iter(a, 10, print);
	std::cout << std::endl;
	iter(b, 10, print);
}