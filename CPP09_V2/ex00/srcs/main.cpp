#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange dB;

	if (ac != 2)
	{
		std::cerr << "usage : ./bitcoin filename" << std::endl;
		return 1;
	}

	try
	{
		dB.init("data.csv");
		dB.calculRate(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught :" << e.what() << std::endl;
	}
}
