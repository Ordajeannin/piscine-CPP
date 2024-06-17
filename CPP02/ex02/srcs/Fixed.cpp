#include "Fixed.hpp"

Fixed::Fixed() : _stock(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nb)
{
	if (nb < (INT_MAX / (1 << _coma)) && nb > (INT_MIN / (1 << _coma)))
		_stock = nb * (1 << _coma);
	else if (nb >= (INT_MAX / (1 << _coma)))
		_stock = INT_MAX;
	else 
		_stock = INT_MIN;
}

Fixed::Fixed(float const nb)
{
	int nb2 = roundf(nb);
	if (nb2 < (INT_MAX / (1 << _coma)) && nb2 > (INT_MIN / (1 << _coma)))
		_stock = roundf(nb * (1 << _coma));
	else if (nb2 >= (INT_MAX / (1 << _coma)))
		_stock = INT_MAX;
	else 
		_stock = INT_MIN;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copie)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

Fixed &Fixed::operator=(const Fixed &other)
{
//	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_stock = other.getRawBits();
	return *this;
}


////////////// arithmetiques ////////////////////

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed value;

//	std::cout << "operator + called" << std::endl;
	if (this->toFloat() + other.toFloat() > FLT_MAX)
		value = Fixed(FLT_MAX);
	else
		value = Fixed(this->toFloat() + other.toFloat());
	return value;
}

Fixed Fixed::operator-(const Fixed &other) const
{	
	Fixed value;

//	std::cout << "operator - called" << std::endl;
	if (this->toFloat() - other.toFloat() < -FLT_MAX)
		value = Fixed(-FLT_MAX);
	else
		value = Fixed(this->toFloat() - other.toFloat());
	return value;
}

Fixed Fixed::operator*(const Fixed &other) const
{	
	Fixed value;

//	std::cout << "operator * called" << std::endl;
	if (this->toFloat() * other.toFloat() > FLT_MAX)
		value = Fixed(FLT_MAX);
	else if (this->toFloat() * other.toFloat() < -FLT_MAX)
		value = Fixed(-FLT_MAX);
	else
		value = Fixed(this->toFloat() * other.toFloat());
	return value;
}

Fixed Fixed::operator/(const Fixed &other) const
{	
	Fixed value;

//	std::cout << "operator / called" << std::endl;
	if (this->toFloat() / other.toFloat() > FLT_MAX)
		value = Fixed(FLT_MAX);
	else if (this->toFloat() / other.toFloat() < -FLT_MAX)
		value = Fixed(-FLT_MAX);
	else
		value = Fixed(this->toFloat() / other.toFloat());
	return value;
}


////////////////// comparaison //////////////////

bool Fixed::operator>(const Fixed &other) const
{
//	std::cout << "operator > called" << std::endl;
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
//	std::cout << "operator < called" << std::endl;
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
//	std::cout << "operator >= called" << std::endl;
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
//	std::cout << "operator <= called" << std::endl;
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
//	std::cout << "operator == called" << std::endl;
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
//	std::cout << "operator != called" << std::endl;
	return (this->toFloat() != other.toFloat());
}


////////////// Incrementation ///////////////////

Fixed &Fixed::operator++()
{
	if (this->_stock < INT_MAX)
		this->_stock++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	if (this->_stock < INT_MAX)
		this->_stock++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	if (this->_stock > INT_MIN)
		this->_stock--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	if (this->_stock > INT_MIN)
		this->_stock--;
	return (temp);
}

///////////////// Methodes //////////////////////

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits called" << std::endl;
	return this->_stock;
}

void Fixed::setRawBits(int const raw) 
{
	this->_stock = raw;
//	std::cout << "setRawBits called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)_stock / (1 << _coma));
}

int Fixed::toInt(void) const
{
	return (_stock / (1 << _coma));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return b;
	else
		return a;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (b > a)
		return b;
	else
		return a;
}

const Fixed &Fixed::max(Fixed const &a, const Fixed &b)
{
	if (b > a)
		return b;
	else
		return a;
}
