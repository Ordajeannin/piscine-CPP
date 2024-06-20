#include "Dog.hpp"

Dog::Dog() : Animal(), _name("Neige"), _type("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(), _name(name), _type("Dog")
{
    std::cout << "Dog constructor called : " << name << std::endl;
}

Dog::Dog(const Dog &c) : Animal(), _name(c._name), _type("Dog")
{
    std::cout << "Dog copy constructor called : " << c._name << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->_name << ", the " << this->_type << ": Waouf!" << std::endl;
}
