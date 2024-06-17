#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("boustiflore"), _hitPoints(10), _energyPoints(10), _atkDamage(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _atkDamage(5)
{
	std::cout << "Constructor called : " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copie)
{
	std::cout << "Contructor by copie called" << std::endl;
	_name = copie._name;
	_hitPoints = copie._hitPoints;
	_energyPoints = copie._energyPoints;
	_atkDamage = copie._atkDamage;
}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl;}

void ClapTrap::attack(ClapTrap &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " seems dead, he cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is KO, he cannot attack." << std::endl;
		return ;
	}
	if (target._hitPoints == 0)
	{
		std::cout << this->_name << ", after reflection, don't want to commit a war crime" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target._name << " (-" << this->_atkDamage << ")" << std::endl;
	target.takeDamage(this->_atkDamage);
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	if (damage >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " felt unalive!" << std::endl;
	}
	else
		this->_hitPoints -= damage;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " seems dead, he cannot heal himself." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is KO, he cannot heal himself." << std::endl;
		return ;
	}
	if (this->_hitPoints == 10)
	{
		std::cout << this->_name << " is already factory-new!" << std::endl;
		return ;
	}
	std::cout << this->_name << " repaire himself (+" << amount << ")" << std::endl;
	this->_hitPoints += amount;
	if (this->_hitPoints > 10)
		this->_hitPoints = 10;
	this->_energyPoints--;
}	
