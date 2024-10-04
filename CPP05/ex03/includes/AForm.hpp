#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_minToSign;
		const int			_minToExec;
		std::string			_target;

	public :
		AForm();
		AForm(std::string name, int toSign, int toExec, std::string target);
		AForm(const AForm &c);
		virtual ~AForm();
		AForm 			&operator=(const AForm &c);

		std::string 	getName() const;
		bool			getSigned() const;
		int				getToSign() const;
		int				getToExec() const;
		std::string		getTarget() const;
		void			beSigned(const Bureaucrat &c);
		void			execute(Bureaucrat const &executor) const;
		virtual void	task() const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public :
				const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public :
				const char *what() const throw();
		};
};
std::ostream		&operator<<(std::ostream &out, const AForm &c);

#endif
