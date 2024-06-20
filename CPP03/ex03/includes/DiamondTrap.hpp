#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copie);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &copie);
		void attack(ClapTrap &target);
		void whoAmI();
};

#endif
