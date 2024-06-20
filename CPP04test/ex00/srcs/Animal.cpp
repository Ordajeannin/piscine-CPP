#include "Animal.hpp"

Animal::Animal() : _type("Most Recent Common Ancestor")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << "Animal constructor called : " << name << std::endl;
}

Animal::Animal(const Animal &copie) : _type(copie._type)
{
	std::cout << "Animal copy constructor called : " << copie._type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*Flopping noises*" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
