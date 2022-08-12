#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x, y;
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &p);
		void operator = (const Point &p);
		Fixed getX() const;
		Fixed getY() const;
		~Point();
};