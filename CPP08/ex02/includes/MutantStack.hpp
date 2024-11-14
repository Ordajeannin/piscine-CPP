#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		~MutantStack() {}

		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		std::deque<T>::iterator begin() {
			return this->c.begin();
		}

		std::deque<T>::iterator end() {
			return this->c.end();
		}

		std::deque<T>::const_iterator begin() const {
			return this->c.begin();
		}

		std::deque<T>::const_iterator end() const {
			return this->c.end();
		}

		std::deque<T>::reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		std::deque<T>::reverse_iterator rend() {
			return this->c.rend();
		}

		std::deque<T>::const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}

		std::deque<T>::const_reverse_iterator rend() const {
			return this->c.rend();
		}
};

