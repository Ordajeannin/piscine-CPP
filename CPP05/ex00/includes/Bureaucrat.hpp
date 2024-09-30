#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string 	_name;
		int 				_grade;
    
	public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &c);
        ~Bureaucrat();
        Bureaucrat 		&operator=(const Bureaucrat &c);
		//std::ostream 	&operator<<(const Bureaucrat &c);
		
		std::string 	getName() const;
		int 			getGrade() const;
		void			downGrade();
		void			upGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
		std::ostream 	&operator<<(std::ostream &out, const Bureaucrat &c);

#endif
