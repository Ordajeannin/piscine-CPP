#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <limits.h>
#include <limits>
#include <string>
#include <stack>

class RPN
{
	private:
		std::string _calculStr;

	public:
		RPN();
		RPN(const std::string &str);
		RPN(const RPN &c);
		RPN &operator=(const RPN &c);
		~RPN(void);

		void calcul();
		
		class BadRNPErrorException : public std::exception
		{
			private:
				std::string _message;
			
			public:
				BadRNPErrorException(std::string message) : _message(message){};
				virtual ~BadRNPErrorException() throw() {};

				const char *what() const throw()
				{
					return (_message.c_str());
				}
		};
};

#endif
