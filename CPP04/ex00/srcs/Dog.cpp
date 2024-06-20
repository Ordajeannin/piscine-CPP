#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &c)
{
    std::cout << "Dog copy constructor called : " << c._type << std::endl;
	*this = c;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &c)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << this->_type << ": WAOUF!" << std::endl;
}
