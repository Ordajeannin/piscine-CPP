#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Door")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
	std::cout << "ScavTrap constructor called : " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copie)
{
	std::cout << "ScavTrap constructor by copy called : " << copie._name << std::endl;
	*this = copie;
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap destructor called" << std::endl;}

ScavTrap &ScavTrap::operator=(const ScavTrap &copie)
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this != &copie)
	{
		_name = copie._name;
		_hitPoints = copie._hitPoints;
		_energyPoints = copie._energyPoints;
		_atkDamage = copie._atkDamage;
	}
	return *this;
}

void ScavTrap::attack(ClapTrap &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << ", the glorious Forsand seems dead, he cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << ", the magnificient Veddinge is KO, he cannot attack." << std::endl;
		return ;
	}
	/*
	if (target._hitPoints == 0)
	{
		std::cout << this->_name << ", after reflection, Bergsbo the Wise don't want to commit a war crime" << std::endl;
		return ;
	}
	*/
	std::cout << this->_name << ", the mighty Oxberg, attacks ";
	target.takeDamage(this->_atkDamage);
	std::cout << " (-" << this->_atkDamage << ")" << std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in Gate keeper mode" << std::endl;
}
