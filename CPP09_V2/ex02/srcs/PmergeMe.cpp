#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	std::string fullInput;
	for (int strIndex = 1; strIndex < ac; strIndex ++)
	{
		std::string numbers = av[strIndex];
		for (size_t i = 0; i < numbers.length(); i ++)
		{
			if (!isdigit(numbers[i]) && numbers[i] != ' ')
				throw(PmergeMe::PmergeMeException("only positiv int must be entered"));//excep
		}
		fullInput += numbers + " ";
	}
	std::istringstream numbersStream(fullInput);
	int firstPair;
	int secondPair;
	_pair = true;

	while (numbersStream >> firstPair)// jeter une exception quand un chiffre plus grand que int apparait ?
	{
		if (!(numbersStream >> secondPair))
		{
			_pair = false;
			_unsortedDequeu.push_back(std::make_pair(firstPair, -1));
			_unsortedList.push_back(std::make_pair(firstPair, -1));
			break ;
		}
		_unsortedDequeu.push_back(std::make_pair(firstPair, secondPair));
		_unsortedList.push_back(std::make_pair(firstPair, secondPair));
	}
}

PmergeMe::PmergeMe(const PmergeMe &c)
{
	*this = c;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &c)
{
	if (this != &c)
	{
		_unsortedDequeu = c._unsortedDequeu;
		_unsortedList = c._unsortedList;
		_sortedDeque = c._sortedDeque;
		_sortedList = c._sortedList;
		_pair = c._pair;
	}
	return *this;
}

PmergeMe::~PmergeMe(void)
{

}


//////////////////////////////////////////getters////////////////////////////////////////////

std::deque<int> PmergeMe::getSortedD()
{
	return _sortedDeque;
}

std::list<int> PmergeMe::getSortedL()
{
	return _sortedList;
}


////////////////////////////////////////////additionals for deque////////////////////////////////////

std::deque<int> pairToDeque(std::deque<std::pair<int, int> > unsorted)
{
	std::deque<int> bigNumber;
	for(std::deque<std::pair<int, int> >::iterator index = unsorted.begin(); index != unsorted.end(); index ++)
	{
		if (index->second != -1)
			bigNumber.push_back(index->second);
	}
	return bigNumber;
}


void mergeBigNumbersDeque(std::deque<int> &bigNumber, int left, int mid, int right)
{
	std::deque<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
	    if (bigNumber[i] <= bigNumber[j])
	        temp.push_back(bigNumber[i++]);
		else
	        temp.push_back(bigNumber[j++]);
	}

	while (i <= mid)
		temp.push_back(bigNumber[i++]);
	while (j <= right)
		temp.push_back(bigNumber[j++]);

	for (int k = left; k <= right; ++k)
	    bigNumber[k] = temp[k - left];
}

std::deque<int> genJacobsthalD(int size)
{
	std::deque<int> jacobsthal;

	jacobsthal.push_back(0);
	if (size > 1)
		jacobsthal.push_back(1);
	for (int i = 2; i < size; i ++)
	{
		if (2 * jacobsthal[i - 2] + jacobsthal[i - 1] >= size)
			break;
		jacobsthal.push_back(2 * jacobsthal[i - 2] + jacobsthal[i - 1]);

	}
	return jacobsthal;
}

////////////////////////////////////////////methodes for deque//////////////////////////////////////

void PmergeMe::sortPairDeque()
{
	int tmp;

	for (std::deque<std::pair<int, int> >::iterator index = _unsortedDequeu.begin(); index != _unsortedDequeu.end(); index ++)
	{
		if (index->first > index->second && index->second != -1)
		{
			tmp = index->second;
			index->second = index->first;
			index->first = tmp;
		}
	}
}

void PmergeMe::sortBigPairDeque(std::deque<int> &unsortedForNow, int left, int right)
{
	if (left >= right)
		return ;
	int mid = (left + right) / 2;

	sortBigPairDeque(unsortedForNow, left, mid);
	sortBigPairDeque(unsortedForNow, mid + 1, right);

	mergeBigNumbersDeque(unsortedForNow, left, mid, right);
}

void PmergeMe::insertLittlePairDeque()
{
	std::deque<int> Jacobsthal = genJacobsthalD(_unsortedDequeu.size());
	int insertValue;

	for (size_t index = 0; index < Jacobsthal.size(); index ++)
	{
		if (index >= _unsortedDequeu.size())
			break;
		insertValue = _unsortedDequeu[Jacobsthal[index]].first;
		_sortedDeque.insert(std::lower_bound(_sortedDeque.begin(), _sortedDeque.end(), insertValue), insertValue);
	}

	for (size_t index = 0; index < _unsortedDequeu.size(); index ++)
	{
		if (std::find(Jacobsthal.begin(), Jacobsthal.end(), index) != Jacobsthal.end())
			continue;
		insertValue = _unsortedDequeu[index].first;
		_sortedDeque.insert(std::lower_bound(_sortedDeque.begin(), _sortedDeque.end(), insertValue), insertValue);
	}
}

double PmergeMe::sortDeque()
{
	clock_t start = clock();
	this->sortPairDeque();
	_sortedDeque = pairToDeque(_unsortedDequeu);
	sortBigPairDeque(_sortedDeque, 0, _sortedDeque.size() - 1);
	insertLittlePairDeque();
	clock_t end = clock();
	double timePassed = double(end - start) / CLOCKS_PER_SEC * 1000;
	return timePassed;
}


////////////////////////////////////////////additionals for list////////////////////////////////////

std::list<int> pairToList(std::list<std::pair<int, int> > unsorted)
{
	std::list<int> bigNumbers;
	for(std::list<std::pair<int, int> >::iterator index = unsorted.begin(); index != unsorted.end(); index ++)
	{
		if (index->second != -1)
			bigNumbers.push_back(index->second);
	}
	return (bigNumbers);
}

void mergeBigNumbersList(std::list<int> &bigNumber, std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right)
{
	std::list<int> temp;
	std::list<int>::iterator i = left;
	std::list<int>::iterator j = mid;
	j ++;
	(void)bigNumber;

	while (i != mid && j != right)
	{
	    if (*i <= *j)
	        temp.push_back(*i ++);
		else
	        temp.push_back(*j ++);
	}

    while (i != mid)
        temp.push_back(*i++);
    while (j != right)
		temp.push_back(*j++);
	j = temp.begin();
	for (i = left; i != right; ++i, ++ j)
	    *i = *j;
}

std::list<int> genJacobsthalL(int size)
{
	std::list<int> jacobsthal;
	int newValue;
	int prevValue = 1;
	int prevPrevValue = 0;

	jacobsthal.push_back(0);
	if (size > 1)
		jacobsthal.push_back(1);
	for (int i = 2; i < size; i ++)
	{
		newValue = 2 * prevPrevValue + prevValue;
		if (newValue >= size)
			break;
		jacobsthal.push_back(newValue);
		prevPrevValue = prevValue;
		prevValue = newValue;
	}
	return jacobsthal;
}


////////////////////////////////////////////methodes for list//////////////////////////////////////

void PmergeMe::sortPairList()
{
	int tmp;

	for (std::deque<std::pair<int, int> >::iterator index = _unsortedDequeu.begin(); index != _unsortedDequeu.end(); index ++)
	{
		if (index->first > index->second && index->second != -1)
		{
			tmp = index->second;
			index->second = index->first;
			index->first = tmp;
		}
	}
}

void PmergeMe::sortBigPairList(std::list<int> &unsortedForNow, std::list<int>::iterator left, std::list<int>::iterator right)
{
	if (left == right)
		return;
	std::list<int>::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);

	sortBigPairList(unsortedForNow, left, mid);
	sortBigPairList(unsortedForNow, ++mid, right);

	mergeBigNumbersList(unsortedForNow, left, mid, right);
}

void PmergeMe::insertLittlePairList()
{
	std::list<std::pair<int, int> >::iterator unsortedIt;
	std::list<int> Jacobsthal = genJacobsthalL(_unsortedList.size());
	int insertValue;

	for (std::list<int>::iterator it = Jacobsthal.begin(); it != Jacobsthal.end(); it ++)
	{
		size_t index = *it;
		if (index >= _unsortedList.size())
			break;

		unsortedIt = _unsortedList.begin();
		std::advance(unsortedIt, index);
		insertValue = unsortedIt->first;

		_sortedList.insert(std::lower_bound(_sortedList.begin(), _sortedList.end(), insertValue), insertValue);
	}

	for (size_t index = 0; index < _unsortedList.size(); index ++)
	{
		if (std::find(Jacobsthal.begin(), Jacobsthal.end(), index) != Jacobsthal.end())
			continue;

		unsortedIt = _unsortedList.begin();
		std::advance(unsortedIt, index);
		insertValue = unsortedIt->first;
		_sortedList.insert(std::lower_bound(_sortedList.begin(), _sortedList.end(), insertValue), insertValue);
	}
}

double PmergeMe::sortList()
{
	clock_t start = clock();
	this->sortPairList();
	_sortedList = pairToList(_unsortedList);
	sortBigPairList(_sortedList, _sortedList.begin(), _sortedList.end());
	insertLittlePairList();
	clock_t end = clock();
	double timePassed = double(end - start) / CLOCKS_PER_SEC * 1000;
	return timePassed;
}

