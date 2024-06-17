#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage : " << av[0] << " <filename> s1 s2" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty() || s2.empty())
	{
		std::cerr << "s1 and s2 cannot be empty" << std::endl;
		return 1;
	}
	try
	{
		replaceInFile(filename, s1, s2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	std::cout << "Replacement done! Check " << filename << ".replace" << std::endl;
	return 0;
}


