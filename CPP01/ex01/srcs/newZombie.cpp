#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	std::cout << "Je cree le Zombie " << name << std::endl;
	Zombie *exemple = new Zombie(name);
	std::cout << "Je return son adresse" << std::endl;
	return (exemple);
}

