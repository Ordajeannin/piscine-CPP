#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	m_name;
		Weapon 		&m_weapon;

	public:
		HumanA(std::string name, Weapon &arme);
		void attack();
};

#endif
