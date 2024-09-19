#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("boustiflore"), _hitPoints(10), _energyPoints(10), _atkDamage(5)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _atkDamage(5)
{
	std::cout << "ClapTrap constructor called : " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copie)
{
	std::cout << "ClapTrap constructor by copy called : " << copie._name << std::endl;
	*this = copie;
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap destructor called" << std::endl;}

ClapTrap &ClapTrap::operator=(const ClapTrap &copie)
{
	std::cout << "ClapTrap copy assignement operator called" << std::endl;
	if (this != &copie)
	{
		_name = copie._name;
		_hitPoints = copie._hitPoints;
		_energyPoints = copie._energyPoints;
		_atkDamage = copie._atkDamage;
	}
	return *this;
}

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
	/*
	if (target._hitPoints == 0)
	{
		std::cout << this->_name << ", after reflection, don't want to commit a war crime" << std::endl;
		return ;
	}
	*/
	std::cout << this->_name << " attacks ";
	target.takeDamage(this->_atkDamage);
	std::cout << " (-" << this->_atkDamage << ")" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	if (damage >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << ". " << this->_name << " felt unalive!";
	}
	else
	{
		std::cout << this->_name;
		this->_hitPoints -= damage;
	}
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
