#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
    	
		T* 				_array;
		unsigned int	_size;


	public:

		// Constructors //
        Array() : _array(NULL), _size(0) { std::cout << "Array default constructor called" << std::endl; }
        Array(unsigned int size) : _array(new T[size]()), _size(size) { std::cout << "Array constructor called, size " << size << std::endl; }
        Array(const Array &c) : _array(new T[c._size]()), _size(c._size)
		{
			for (unsigned int i = 0; i < this->_size; i++)
			{
				this->_array[i] = c._array[i];
			}
			std::cout << "Array copy constructor called" << std::endl;
		}

		// Destructor //
		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			delete[] this->_array;
		}

		// Operator overload //
		Array& operator=(const Array &c)
		{
			if (this != &c)
			{
				delete[] this->_array;
				this->_array = new T[c._size];
				this->_size = c._size;
				for (unsigned int i = 0; i < _size; i++)
				{
					this->_array[i] = c._array[i];
				}
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			else
				return _array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			else
				return _array[index];
		}

		// Getters //
		unsigned int getSize() const
		{
			return this->_size;
		}

		// Exceptions //
		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw() { return "Array index out of bounds"; };
		};
};

#endif
