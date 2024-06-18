#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Door")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_atkDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_atkDamage = 30;
	std::cout << "FragTrap constructor called : " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap(c)
{
	std::cout << "FragTrap copy constructor called : " << c._name << std::endl;
}

FragTrap::~FragTrap() {std::cout << "FragTrap destructor called" << std::endl;}

void FragTrap::attack(ClapTrap &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << ", the glorious Brimnes seems dead, he cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << ", the magnificient Kleppstad is KO, he cannot attack." << std::endl;
		return ;
	}
	/*
	if (target._hitPoints == 0)
	{
		std::cout << this->_name << ", after reflection, Bergsbo the Wise don't want to commit a war crime" << std::endl;
		return ;
	}
	*/
	std::cout << this->_name << ", the mighty Vihals, attacks ";
	target.takeDamage(this->_atkDamage);
	std::cout << " (-" << this->_atkDamage << ")" << std::endl;
	this->_energyPoints--;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->_name << " : Hey dudes, chiiiiiill, what about a high fives instead?" << std::endl;
}
