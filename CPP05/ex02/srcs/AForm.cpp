#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm 28C"), _signed(0), _minToSign(150), _minToExec(150), _target("default")
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign, int exec, std::string target) : _name(name), _signed(0), _minToSign(sign), _minToExec(exec), _target(target) 
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else
		std::cout << "AForm constructor called : " << name << " -> " << target << std::endl;
}

AForm::AForm(const AForm& c) : _name(c._name), _signed(0), _minToSign(c._minToSign), _minToExec(c._minToExec), _target(c._target)
{
	std::cout << "AForm copy constructor called : " << c._name << " -> " << c._target << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called : " << this->_name << std::endl;
}

AForm &AForm::operator=(const AForm &c)
{
	std::cout << "AForm copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->_signed = c._signed;
		this->_target = c._target;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool		AForm::getSigned() const
{
	return this->_signed;
}

int			AForm::getToSign() const
{
	return this->_minToSign;
}

int			AForm::getToExec() const
{
	return this->_minToExec;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

void		AForm::beSigned(const Bureaucrat& c)
{
	if (c.getGrade() <= this->_minToSign)
	{
		if (this->_signed == 1)
			throw FormAlreadySignedException();
		this->_signed = 1;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

void		AForm::execute(const Bureaucrat &e) const
{
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	else if (e.getGrade() > this->getToExec())
		throw Bureaucrat::GradeTooLowException();
	else
		task(e);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low, must be <= 150";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form Grade too high, must be >= 1";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form isn't signed yet, can't execute";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form already signed, can't sign it again";
}

std::ostream &operator<<(std::ostream &out, const AForm &c)
{
	out << c.getName() << " (" << c.getSigned() << "/"  << c.getToSign() << "/" << c.getToExec() << ")";
	return out;
}












