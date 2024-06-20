#ifndef FRAGCLAP_HPP
#define FRAGCLAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copie);
		~FragTrap();
		FragTrap &operator=(const FragTrap &copie);
		void attack(ClapTrap &target);
		void highFivesGuys(void);
};

#endif
