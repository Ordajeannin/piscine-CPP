#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copie);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &copie);
		void attack(ClapTrap &target);
		void guardGate();
};

#endif
