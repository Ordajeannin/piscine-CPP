#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	private:
		const unsigned int	_maxSize;
		std::vector<int>	_span;

	public:
		Span();
		Span(const unsigned int maxSize);
		Span(const Span &c);
		~Span();

		Span &operator=(const Span &c);

		void 			addNumber(int n);
		unsigned int 	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			printSpan() const;
		
		class NotEnoughtNumbers : public std::exception
		{
			const char* what() const throw() { 
				return "Not enought numbers to compare, must be at least 2"; }
		};
		
		class TooMuchNumbers : public std::exception
		{
			const char* what() const throw() { 
				return "Already too much numbers in the Span"; }
		};

		class SpanTooSmall : public std::exception
		{
			const char* what() const throw() {
				return "Unable to copy, not enough place in span destination/span source too big"; }
		};

		template <typename it>
		void	addNumbers(it begin, it end)
		{
			if (std::distance(begin, end) > static_cast<int>(_maxSize - _span.size()))
				throw TooMuchNumbers();
			_span.insert(_span.end(), begin, end);
		}
};	
#endif
