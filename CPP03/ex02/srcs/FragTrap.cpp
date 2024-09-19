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

FragTrap::FragTrap(const FragTrap &copie)
{
	std::cout << "FragTrap constructor by copy called : " << copie._name << std::endl;
	*this = copie;
}

FragTrap::~FragTrap() {std::cout << "FragTrap destructor called" << std::endl;}

FragTrap &FragTrap::operator=(const FragTrap &copie)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this != &copie)
	{
		_name = copie._name;
		_hitPoints = copie._hitPoints;
		_energyPoints = copie._energyPoints;
		_atkDamage = copie._atkDamage;
	}
	return *this;
}

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
	if (this->_hitPoints != 0)
		std::cout << this->_name << " : Hey dudes, chiiiiiill, what about a high fives instead?" << std::endl;
	else
		std::cout << this->_name << " : esygfucygagrivquyagia... (seems like he want to say something, but maybe it's harder when you're dead.)" << std::endl;
}
