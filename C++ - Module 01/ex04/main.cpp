#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage: ./program [filename] s1 s2\n";
		return 1;
	}

	std::string fname(av[1]), s1(av[2]), s2(av[3]), buffer, replace;

	std::ifstream in(fname);
	if (in.fail()) {
		std::cerr << "Fail to open " << fname << '\n';
		return 2;
	}

	std::ofstream out(fname + ".replace");
	if (out.fail()) {
		std::cerr << "Fail to open " << fname << ".replace\n";
		return 2;
	}

	std::getline(in, buffer, '\0');
	in.close();

	for (int i = 0; i < int(buffer.length()); i++) {
		if (buffer.substr(i, s1.length()) == s1) {
			replace += s2;
			i += s1.length() - 1;
		}
		else {
			replace += buffer[i];
		}
	}

	out << replace;
	out.close();
}
