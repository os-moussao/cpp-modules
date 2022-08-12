#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point &p) { *this = p; }

void Point::operator = (const Point &p) {
	x = p.getX();
	y = p.getY();
}

Fixed Point::getX() const {
	return x;
}
Fixed Point::getY() const {
	return y;
}

Point::~Point() {}