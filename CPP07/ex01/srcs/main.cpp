#include <iostream>
#include "IterTemplate.hpp"

template <typename T>
void print_element(const T &a)
{
	std::cout << a << std::endl;
}

template <typename T>
void incr_element(T &a)
{
	a++;
}

int main()
{
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "------ Tests for an array of int ------" << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		int length = sizeof(arr) / sizeof(arr[0]);

		std::cout << "array values :" << std::endl;
		::iter(arr, length, print_element<int>);
		std::cout << std::endl;
		std::cout << "<proceed to incr all elements>" << std::endl;
		std::cout << std::endl;
		::iter(arr, length, incr_element<int>);
		std::cout << "array values after incr :" << std::endl;
		::iter(arr, length, print_element<int>);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "----- Tests for an array of char ------" << std::endl;
		char arr[] = {'h', 'e', 'l', 'l', 'o'};
		int length = sizeof(arr) / sizeof(arr[0]);
		std::cout << "array values :" << std::endl;
		::iter(arr, length, print_element<char>);
		std::cout << std::endl;
		std::cout << "<proceed to incr all elements>" << std::endl;
		std::cout << std::endl;
		::iter(arr, length, incr_element<char>);
		std::cout << "array values after incr :" << std::endl;
		::iter(arr, length, print_element<char>);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "---- Tests for an array of doubles ----" << std::endl;
		double arr[] = {1.0, 2.3, 3.4, 4.5, 5.6};
		int length = sizeof(arr) / sizeof(arr[0]);

		std::cout << "array values :" << std::endl;
		::iter(arr, length, print_element<double>);
		std::cout << std::endl;
		std::cout << "<proceed to incr all elements>" << std::endl;
		std::cout << std::endl;
		::iter(arr, length, incr_element<double>);
		std::cout << "array values after incr :" << std::endl;
		::iter(arr, length, print_element<double>);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}

