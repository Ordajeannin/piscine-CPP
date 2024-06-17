#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type) {}

std::string &Weapon::getType()
{
	return m_type;
}

void	Weapon::setType(const std::string &newType)
{
	m_type = newType;
}
