#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int decimalPoint)
		: rawBits(decimalPoint << fraction) {}

Fixed::Fixed(const float floatPoint) {
	rawBits = roundf(floatPoint * (float)(1 << fraction));
}

void Fixed::operator = (const Fixed &fixed) {
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

bool Fixed::operator > (const Fixed &fx) const {
	return rawBits > fx.getRawBits();
}

bool Fixed::operator >= (const Fixed &fx) const {
	return rawBits >= fx.getRawBits();
}

bool Fixed::operator < (const Fixed &fx) const {
	return rawBits < fx.getRawBits();
}

bool Fixed::operator <= (const Fixed &fx) const {
	return rawBits <= fx.getRawBits();
}

bool Fixed::operator == (const Fixed &fx) const {
	return rawBits == fx.getRawBits();
}

bool Fixed::operator != (const Fixed &fx) const {
	return rawBits != fx.getRawBits();
}

Fixed Fixed::operator + (const Fixed &fx) const {
	return Fixed(toFloat() + fx.toFloat());
}

Fixed Fixed::operator - (const Fixed &fx) const {
	return Fixed(toFloat() - fx.toFloat());
}

Fixed Fixed::operator * (const Fixed &fx) const {
	return Fixed(toFloat() * fx.toFloat());
}

Fixed Fixed::operator / (const Fixed &fx) const {
	return Fixed(toFloat() / fx.toFloat());
}

Fixed Fixed::operator ++ () {
	return ++rawBits, *this;
}

Fixed Fixed::operator ++ (int x) {
	(void)x;
	Fixed ret = *this;
	return ++rawBits, ret;
}

Fixed Fixed::operator -- () {
	return --rawBits, *this;
}

Fixed Fixed::operator -- (int x) {
	(void)x;
	Fixed ret = *this;
	return --rawBits, ret;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a >= b? a: b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a >= b? a: b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a <= b? a: b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a <= b? a: b;
}

Fixed::~Fixed() {}