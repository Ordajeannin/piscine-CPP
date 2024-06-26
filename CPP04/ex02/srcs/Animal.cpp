#include "Animal.hpp"

Animal::Animal() : _type("Most Recent Common Ancestor")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor called : " << type << std::endl;
}

Animal::Animal(const Animal &c)
{
    std::cout << "Animal copy constructor called : " << c._type << std::endl;
	*this = c;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &c)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}
