#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), FragTrap(), ScavTrap(), _name("Diamond")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_atkDamage = FragTrap::_atkDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_atkDamage = FragTrap::_atkDamage;
	std::cout << "DiamondTrap constructor called : " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copie)
{
	std::cout << "DiamondTrap constructor by copy called : " << copie._name << std::endl;
	*this = copie;
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap destructor called" << std::endl;}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copie)
{
	std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this != &copie)
	{
		_name = copie._name;
		_hitPoints = copie._hitPoints;
		_energyPoints = copie._energyPoints;
		_atkDamage = copie._atkDamage;
	}
	return *this;
}

void DiamondTrap::attack(ClapTrap &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

