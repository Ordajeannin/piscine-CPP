#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_minToSign;
		const int			_minToExec;

	public :
		Form();
		Form(std::string name, int toSign, int toExec);
		Form(const Form &c);
		~Form();
		Form 		&operator=(const Form &c);

		std::string getName() const;
		bool		getSigned() const;
		int			getToSign() const;
		int			getToExec() const;
		bool		beSigned(const Bureaucrat &c);

		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();
		};		
};
std::ostream		&operator<<(std::ostream &out, const Form &c);

#endif
