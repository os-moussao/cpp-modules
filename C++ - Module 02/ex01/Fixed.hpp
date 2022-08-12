#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int rawBits;
		static const int fraction;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int decimalPoint);
		Fixed(const float floatPoint);
		void operator = (const Fixed &fixed);
		int getRawBits(void) const ;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& dt);