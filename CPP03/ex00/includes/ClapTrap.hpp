#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _atkDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copie);
		~ClapTrap();

		void attack(ClapTrap &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
