#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <algorithm>

class PmergeMe
{
	private:
		std::deque<std::pair<int, int> > _unsortedDequeu;
		std::deque<int> _sortedDeque;
		std::list<std::pair<int, int> > _unsortedList;
		std::list<int> _sortedList;
		bool _pair;

	public:
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &cp);
		~PmergeMe(void);

		std::deque<int> getSortedD();
		std::list<int> getSortedL();

		double sortDeque();
		void sortPairDeque();
		void sortBigPairDeque(std::deque<int> &unsortedForNow, int left, int right);
		void insertLittlePairDeque();
		double sortList();
		void sortPairList();
		void sortBigPairList(std::list<int> &unsortedForNow, std::list<int>::iterator left, std::list<int>::iterator right);
		void insertLittlePairList();

		class PmergeMeException : public std::exception
		{
			private:
				std::string _message;
		
			public :
				PmergeMeException(std::string message) : _message(message) {}
				virtual ~PmergeMeException() throw() {};
				const char *what() const throw()
				{
					return (_message.c_str());
				}
		};
};

#endif
