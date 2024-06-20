#include "Cat.hpp"

Cat::Cat() : Animal(), _name("Felix"), _type("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(), _name(name), _type("Cat")
{
    std::cout << "Cat constructor called : " << name << std::endl;
}

Cat::Cat(const Cat &c) : Animal(), _name(c._name), _type(c._type)
{
    std::cout << "Cat copy constructor called : " << c._name << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->_name << ", the " << this->_type << ": Meowwwwww" << std::endl;
}
