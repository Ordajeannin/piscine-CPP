#include "Easy.hpp"
#include <vector>
#include <list>

int main()
{
	{
		std::cout << "=== Tests vector ===" << std::endl;
		std::vector<int> vector;
		for (int i = 1; i <= 5; ++i) vector.push_back(i);
	
		try
		{
			std::vector<int>::iterator it = easyfind(vector, 3);
			std::cout << "Found in vector : " << *it << std::endl;
		}
		catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	
		try
		{
			std::vector<int>::iterator it = easyfind(vector, 10);
			std::cout << "Found in vector : " << *it << std::endl;
		}
		catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "=== Tests list ===" << std::endl;
		std::list<int> list;
		for (int i = 1; i <= 5; ++i) list.push_back(i);

		try
		{
			std::list<int>::iterator it = easyfind(list, 4);
			std::cout << "Found in list : " << *it << std::endl;
		}
		catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
		
		try
		{
			std::list<int>::iterator it = easyfind(list, 10);
			std::cout << "Found in list : " << *it << std::endl;
		}
		catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
		std::cout << std::endl << std::endl;
	}
	return 0;
}
