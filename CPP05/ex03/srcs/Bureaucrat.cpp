#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("exemple"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
    std::cout << "Bureaucrat constructor called : " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &c) : _name(c._name)
{
    std::cout << "Bureaucrat copy constructor called : " << c._name << std::endl;
    *this = c;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
    std::cout << "Bureaucrat copy assignement operator called" << std::endl;
    if (this != &c)
		this->_grade = c._grade;
    return *this;
}
/*
std::ostream &Bureaucrat::operator<<(std::ostream& out, const Bureaucrat &c)
{
	std::cout << "Bureaucrat ostream overload called" << std::endl;
	out << c.getName() << "(grade " << c.getGrade() << ")";
	return out;
}
*/

std::ostream &operator<<(std::ostream& out, const Bureaucrat &c)
{
//	std::cout << "Bureaucrat ostream overload called" << std::endl;
	out << c.getName() << " (grade " << c.getGrade() << ")";
	return out;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::upGrade()
{
	std::cout << *this << " ask for an upGrade : ";
	if (this->_grade < 2)
		std::cout << "You're already the Boss, Boss" << std::endl;
	else
	{
		this->_grade--;
		std::cout << "Grade updated -> you're now grade " << this->_grade << std::endl;
	}
}

void Bureaucrat::downGrade()
{
	std::cout << *this << " is the target for a downGrade : ";
	if (this->_grade > 149)
		std::cout << "you can't have a lower grade, lill carpet" << std::endl;
	else
	{
		this->_grade++;
		std::cout << "Grade updated -> you're now grade " << this->_grade << std::endl;
	}
}

/*
void Bureaucrat::signForm(AForm &t)
{
	try
	{
*/		

void Bureaucrat::signForm(AForm &t)
{
	try
	{
		t.beSigned(*this);
		std::cout << *this << " signed " << t << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << *this << " couldn't sign " << t << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &t) const
{
	try
	{
		t.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << *this << " cannot execute " << t << ", " << e.what() << std::endl;
		return;
	}
	std::cout << *this << " executed " << t << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade du bureaucrat trop eleve, degonflage de chevilles necessaire";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade du bureaucrat trop faible";
}
