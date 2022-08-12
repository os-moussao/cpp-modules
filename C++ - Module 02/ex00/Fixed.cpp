#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

void Fixed::operator = (const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = fixed.getRawBits();
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}