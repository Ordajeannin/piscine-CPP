#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./RPN \"[...]\"" << std::endl;
		return 1;
	}
	try
	{
		RPN polishCalcul(av[1]);
		polishCalcul.calcul();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
