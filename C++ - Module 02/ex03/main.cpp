#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a,
		 Point const b,
		 Point const c,
		 Point const point);



int main( void ) {
	Point a(Fixed((float)0), Fixed((float)0));
	Point b(Fixed((float)0), Fixed((float)3));
	Point c(Fixed((float)3), Fixed((float)0));

	Point p1(Fixed((float)1), Fixed((float)1));
	Point p2(Fixed((float)-1), Fixed((float)1));

	std::cout << ( bsp(a,b,c,p1)? "Inside" : "Outside" ) << std::endl;
	std::cout << ( bsp(a,b,c,a)? "Inside" : "Outside" ) << std::endl;
	std::cout << ( bsp(a,b,c,b)? "Inside" : "Outside" ) << std::endl;
	std::cout << ( bsp(a,b,c,c)? "Inside" : "Outside" ) << std::endl;
	std::cout << ( bsp(a,b,c,c)? "Inside" : "Outside" ) << std::endl;
	std::cout << ( bsp(a,b,c,p2)? "Inside" : "Outside" ) << std::endl;
}