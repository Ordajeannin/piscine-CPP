#include "ScalarConverter.hpp"

/*
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "invalid input" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
    return 0;
}
*/

int main()
{
	std::cout << "test : 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << "test : 'a'" << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << std::endl;
	
	std::cout << "test : 'A'" << std::endl;
	ScalarConverter::convert("'A'");
	std::cout << std::endl;

	std::cout << "test : 42" << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	
	std::cout << "test : -42" << std::endl;
	ScalarConverter::convert("-42");
	std::cout << std::endl;
	
	std::cout << "test : 42.0" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	
	std::cout << "test : -42.0" << std::endl;
	ScalarConverter::convert("-42.0");
	std::cout << std::endl;
	
	std::cout << "test : 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	
	std::cout << "test : -42f" << std::endl;
	ScalarConverter::convert("-42f");
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "test : +inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	
	std::cout << "test : -inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	
	std::cout << "test : +inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	
	std::cout << "test : -inff" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	
	std::cout << "test : nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	
	std::cout << "test : nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	return 0;
}
