#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
    std::cout << "Cat copy constructor called : " << c._type << std::endl;
	*this = c;
}

Cat::~Cat()
{
	delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
		_brain = new Brain(*c._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " : Meowwwww" << std::endl;
}
