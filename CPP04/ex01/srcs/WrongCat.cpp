#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c)
{
    std::cout << "WrongCat copy constructor called : " << c._type << std::endl;
	*this = c;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << this->_type << " : [bip][bip][confidentiel][bip][bip]" << std::endl;
}
