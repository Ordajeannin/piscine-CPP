#include "Span.hpp"

int main()
{
	std::cout << std::endl;
	Span sp(5);
	Span little;
	Span big(12000);
	Span ps(5);
	Span test(5);

	try
	{
		std::cout << std::endl << "--- Tests shortest/longest ---" << std::endl;
		sp.addNumber(3);

		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl << "--- Test normal cases --- " << std::endl;
		sp.addNumber(1);
		sp.addNumber(4);
		sp.addNumber(1);
		sp.addNumber(5);

		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- Test span full ---" << std::endl;
		sp.addNumber(12);
		
		std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- Test = overload ---" << std::endl;
		std::cout << "proceed to copy sp in big (empty)..." << std::endl;
		big = sp;
		std::cout << "big content :";
		big.printSpan();
	
		std::cout << "proceed to copy big in little (not compatible size)..." << std::endl;
		little = big;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- Test addNumbers ---" << std::endl;
		std::cout << "proceed to add a range of numbers in ps ..." << std::endl;
		std::vector<int> range;
		range.push_back(5);
		range.push_back(1);
		range.push_back(4);
		range.push_back(1);
		range.push_back(3);
		ps.addNumbers(range.begin(), range.end());
		std::cout << "ps content : ";
		ps.printSpan();
		std::cout << "proceed to add Too much numbers in test ..." << std::endl;
		range.push_back(0);
		test.addNumbers(range.begin(), range.end());
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}


	std::cout << std::endl;
	return 0;
}

