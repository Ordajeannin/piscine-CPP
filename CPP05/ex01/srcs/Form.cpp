#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form 28C"), _signed(0), _minToSign(150), _minToExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _signed(0), _minToSign(sign), _minToExec(exec)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else
		std::cout << "Form constructor called : " << name << std::endl;
}

Form::Form(const Form& c) : _name(c._name), _signed(0), _minToSign(c._minToSign), _minToExec(c._minToExec)
{
	std::cout << "Form copy constructor called : " << c._name << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called : " << this->_name << std::endl;
}

Form &Form::operator=(const Form &c)
{
	std::cout << "Form copy assignement operator called" << std::endl;
	if (this != &c)
		this->_signed = c._signed;
	return *this;
}
std::string Form::getName() const
{
	return this->_name;
}

bool		Form::getSigned() const
{
	return this->_signed;
}

int			Form::getToSign() const
{
	return this->_minToSign;
}

int			Form::getToExec() const
{
	return this->_minToExec;
}

bool		Form::beSigned(const Bureaucrat& c)
{
	if (c.getGrade() <= this->_minToSign)
	{
		this->_signed = 1;
		return 1;
	}
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high, must be >= 1";
}

std::ostream &operator<<(std::ostream &out, const Form &c)
{
	out << c.getName() << " (" << c.getSigned() << "/"  << c.getToSign() << "/" << c.getToExec() << ")";
	return out;
}












