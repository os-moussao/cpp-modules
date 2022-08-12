#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int decimalPoint) : rawBits(decimalPoint << fraction) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatPoint) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(floatPoint * (float)(1 << fraction));
}

void Fixed::operator = (const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = fixed.getRawBits();
}

int Fixed::getRawBits(void) const {
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (float)rawBits / (1 << fraction);
}

int Fixed::toInt(void) const {
	return rawBits >> fraction;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
	os << fx.toFloat();
	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}