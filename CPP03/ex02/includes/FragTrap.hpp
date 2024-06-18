#ifndef FRAGCLAP_HPP
#define FRAGCLAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copie);
		~FragTrap();

		void attack(ClapTrap &target);
		void highFivesGuys(void);
};

#endif
