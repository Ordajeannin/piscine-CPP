#include "PmergeMe.hpp"

void printUnsorted(int argc, char *argv[])
{
	std::cout << "-------------------------unsorted-----------------------\n";
	std::cout << "before:\t";
	for (int i = 1; i < argc; i ++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

void printSorted(std::deque<int> c)
{
	std::cout << "-------------------------sorted-----------------------\n";
	std::cout << "after:\t";
 	for (std::deque<int>::iterator index = c.begin(); index != c.end(); index ++)
		std::cout << *index << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "wrong arg number"<< std::endl;
		return 1;
	}
	try
	{
		double timeToSortD;
		double timeToSortL;
		PmergeMe sortingClass(argc ,argv);
		
		printUnsorted(argc, argv);
		timeToSortD = sortingClass.sortDeque();
		timeToSortL = sortingClass.sortList();
		printSorted(sortingClass.getSortedD());
		std::cout << "time passed to sort deque with " << argc - 1 << " element :" << timeToSortD << "ms" << std::endl;
		std::cout << "time passed to sort list with " << argc - 1 << " element :" << timeToSortL << "ms" << std::endl;
	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exeption caught :" << e.what() << std::endl;
	}
}
