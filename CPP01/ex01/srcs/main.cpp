#include "Zombie.hpp"

int main()
{
	std::cout << "JE SUIS DANS LE MAIN" << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	int 		N = 5;
	std::string	name = "porte";
	Zombie *horde = zombieHorde(N, name);
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete []horde;
	return (0);
}
