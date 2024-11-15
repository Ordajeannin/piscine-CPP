#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <iostream>

int main()
{
	{
		std::cout << "--- test du sujet ---" << std::endl;
		std::cout << "MutantStack:" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "----------------------" << std::endl;
		std::cout << "List:" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "--- test iterateurs ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
    	mstack.push(2);
	    mstack.push(3);
	    mstack.push(4);
	    mstack.push(5);

		std::cout << "-> normaux" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
    	MutantStack<int>::iterator ite = mstack.end();
    	while (it != ite) {
        	std::cout << *it << " ";
        	++it;
    	}
    	std::cout << std::endl;

		std::cout << "-> constant" << std::endl;
		const MutantStack<int> cmstack = mstack;
		MutantStack<int>::const_iterator cit = cmstack.begin();
		MutantStack<int>::const_iterator cite = cmstack.end();
		while (cit != cite) {
			std::cout << *cit << " ";
			++cit;
		}
    	std::cout << std::endl;

		std::cout << "-> inverse" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite) {
			std::cout << *rit << " ";
			++rit;
		}
    	std::cout << std::endl;

		std::cout << "-> inverse constant" << std::endl;
		MutantStack<int>::const_reverse_iterator crit = cmstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = cmstack.rend();
		while (crit != crite) {
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl;
	}	
/*	{
		std::cout << "--- tests perso ---" << std::endl;
		std::stack<int> i;

		i.push_back(1);
		std::stack<int>::const_iterator it = i.begin();
		std::cout << *it;
	} */
	return 0;
}
