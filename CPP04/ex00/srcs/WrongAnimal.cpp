#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Most Recent Common Ancestor")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor called : " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
    std::cout << "WrongAnimal copy constructor called : " << c._type << std::endl;
	*this = c;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &c)
{
	std::cout << "WrongAnimal copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->_type << ": *Flopping noises intensifies*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
