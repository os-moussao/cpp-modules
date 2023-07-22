#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        return std::cerr << OPEN_ERR, 1;
    }

    std::ifstream input(av[1]);

    if (input.fail()) {
        return std::cerr << OPEN_ERR, 1;
    }

    if (head(input) != "date | value") {
        return std::cerr << "Error: invalid input file format.\n", 1;
    }

    loadDatabase();

    std::string squery;
    while (getline(input, squery)) {
        std::stringstream query(squery);
        std::cout << handle(query, squery) << '\n';
    }
}