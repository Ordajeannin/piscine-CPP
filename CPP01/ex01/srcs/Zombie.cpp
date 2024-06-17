#include "Zombie.hpp"

Zombie::Zombie()
{
	m_name = "random";
	std::cout << "encore un..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	m_name = name;
	std::cout << m_name << " est (de nouveau) vivant!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << m_name << " est (encore) mort" << std::endl;
}

void Zombie::announce()
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	std::cout << "on change de nom! old : " << m_name << " | new : " << name << std::endl;
	m_name = name;
}
