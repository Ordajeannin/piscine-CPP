#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &c)
{
    std::cout << "Brain copy constructor called"  << std::endl;
	*this = c;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &c)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	if (this != &c)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = c._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	return _ideas[index];
}
void Brain::setIdea(int index, const std::string &idea)
{
	_ideas[index] = idea;
}
