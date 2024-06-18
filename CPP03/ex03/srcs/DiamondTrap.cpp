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

DiamondTrap::DiamondTrap(const DiamondTrap &c) : ClapTrap(c), FragTrap(c), ScavTrap(c), _name(c._name)
{
	std::cout << "DiamondTrap copy constructor called : " << c._name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(ClapTrap &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

