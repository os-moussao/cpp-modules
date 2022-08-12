#include "Point.hpp"
#include "Fixed.hpp"

float absf(float x) {
	return x < 0. ? -x : x;
}

Fixed area(const Point &a, const Point &b, const Point &c) {
	Fixed x1, x2, x3, y1, y2, y3;
	x1 = a.getX(), y1 = a.getY();
	x2 = b.getX(), y2 = b.getY();
	x3 = c.getX(), y3 = c.getY();
	float ar = ((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2))).toFloat();
	return Fixed(absf(ar)/2);
}

bool bsp(Point const a,
		 Point const b,
		 Point const c,
		 Point const p)
{
	Fixed abc, abp, apc, pbc;
	abc = area(a, b, c);
	abp = area(a, b, p);
	apc = area(a, p, c);
	pbc = area(p, b, c);
	return abc == (abp + apc + pbc);
}