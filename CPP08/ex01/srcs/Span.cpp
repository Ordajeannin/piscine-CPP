#include "Span.hpp"

Span::Span() : _maxSize(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const unsigned int maxSize) : _maxSize(maxSize)
{
	std::cout << "Span constructor called : maxSize " << maxSize << std::endl;
}

Span::Span(const Span &c)
{
	*this = c;
	std::cout << "Span copy constructor called" << std::endl;
}

Span &operator=(const Span &c)
{
	if (*this != c)
	{
		this->_maxSize = c._maxSize;
		this->_span = c._Span;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_span.size() > this->_maxSize)
		throw ToMuchNumbers();
	this->_span.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (this->_span.size() < 2)
		throw NotEnoughtNumbers();

	unsigned int result = UINT_MAX;
	std::vetor<int> tmp = this->_span;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
	{
		if ((i + 1) != tmp.end() && static_cast<unsigned int>(*(i + 1) - *i) < result)
			result = static_cast<unsigned int>(*(i + 1) - *i);
	}
	return result;
}

unsigned int Span::longestSpan() const
{
	if (this->_span.size() < 2)
		throw NotEnoughtNumbers();

	std::vector<int>::const_iterator max = std::max_element(this->_span.begin(), this->_span.end());
	std::vector<int>::const_iterator min = std::min_element(this->_span.begin(), this->_span.end());

	return (static_cast<unsigned int>(*max - *min));
}
