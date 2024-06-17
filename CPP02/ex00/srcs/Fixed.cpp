#include "Fixed.hpp"

Fixed::Fixed(int nb) : _stock(nb) {std::cout << "Default constructor called" << std::endl;}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

Fixed::Fixed(const Fixed &copie)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_stock = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return this->_stock;
}

void Fixed::setRawBits(int const raw) 
{
	this->_stock = raw;
	std::cout << "setRawBits called" << std::endl;
}
