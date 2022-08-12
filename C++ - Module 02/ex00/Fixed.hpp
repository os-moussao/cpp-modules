#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int rawBits;
		static const int fraction;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		void operator = (const Fixed &fixed);
		int getRawBits(void) const ;
		void setRawBits(int const raw);
		~Fixed();
};