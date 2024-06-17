#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string m_type;
	public:
		Weapon(std::string type);
		std::string &getType();
		void setType(const std::string &newType);
};

#endif
