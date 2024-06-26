#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
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
	delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &c)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
		_brain = new Brain(*c._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << this->_type << ": WAOUF!" << std::endl;
}
