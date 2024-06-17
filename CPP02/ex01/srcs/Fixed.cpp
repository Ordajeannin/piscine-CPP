#include "Fixed.hpp"

Fixed::Fixed() : _stock(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(int const nb)
{
	if (nb < (INT_MAX / (1 << _coma)) && nb > (INT_MIN / (1 << _coma)))
		_stock = nb * (1 << _coma);
	else
		_stock = 0;
}

Fixed::Fixed(float const nb)
{
	int nb2 = roundf(nb);
	if (nb2 < (INT_MAX / (1 << _coma)) && nb2 > (INT_MIN / (1 << _coma)))
		_stock = roundf(nb * (1 << _coma));
	else
		_stock = 0;
}

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

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
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

float Fixed::toFloat(void) const
{
	return ((float)_stock / (1 << _coma));
}

int Fixed::toInt(void) const
{
	return (_stock / (1 << _coma));
}
