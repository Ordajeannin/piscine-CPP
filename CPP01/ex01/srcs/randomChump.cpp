#include "Zombie.hpp"

void	randomChump(std::string name)
{
	std::cout << "Je cree le Zombie " << name << std::endl;
	Zombie volets(name);
	volets.announce();
	std::cout << "Je vais quitter randomChump sans rien renvoyer" << std::endl;
}
