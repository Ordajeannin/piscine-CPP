#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return "Element not found in the given container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
