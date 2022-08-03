#include "Harl.hpp"

int main()
{
	Harl obj;

	obj.complain("info");	
	obj.complain("debug");	
	obj.complain("error");	
	obj.complain("warning");	
	obj.complain("info");	
	obj.complain("warning");	
}
