#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <levels>" <<std::endl;
		return 1;
	}

	Harl harl;
	std::string level = av[1];
	harl.filterComplaints(level);
	return 0;
}
