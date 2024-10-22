#include "FewTemplates.hpp"
#include <iostream>

int main()
{
	{
	std::cout << "Test with int" << std::endl;
    int a = 10, b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "Min of a and b: " << min(a, b) << std::endl;
    std::cout << "Max of a and b: " << max(a, b) << std::endl;

    std::cout << "------------------------------------" << std::endl;

	std::cout << "Test with doubles" << std::endl;
    double x = 5.5, y = 3.3;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    std::cout << "Min of x and y: " << min(x, y) << std::endl;
    std::cout << "Max of x and y: " << max(x, y) << std::endl;

    std::cout << "------------------------------------" << std::endl;

	std::cout << "Test with char" << std::endl;
    char c1 = 'a', c2 = 'z';
    std::cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
    swap(c1, c2); 
    std::cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
    std::cout << "Min of c1 and c2: " << min(c1, c2) << std::endl;
    std::cout << "Max of c1 and c2: " << max(c1, c2) << std::endl;

	std::cout << std::endl << std::endl;
	}
	

	std::cout << "-------- TESTS DU SUJET ------------" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
    return 0;
}
