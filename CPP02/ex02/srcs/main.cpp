#include "Fixed.hpp"

int main( void )
{
	Fixed a(10000000);
	Fixed b(-112);

	std::cout << std::endl << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	////////////// comparaison ////////////////////////////
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	std::cout << std::endl;

	//////////////////// operations ///////////////////////
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << std::endl;

	///////////////////// incrementation //////////////////
	std::cout << "a = " << a << std::endl;
	std::cout << "++a -> " << ++a << std::endl;
	std::cout << "--a -> " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++, a--, a = | " << a++ << " " << a-- << " " << a << std::endl;
	std::cout << std::endl;
	
	///////////////////// methode /////////////////////////
	std::cout << "the bigger value is : " << Fixed::max(a, b) << std::endl;
	std::cout << "the smaller value is : " << Fixed::min(a, b) << std::endl;

	return 0;
}
	
