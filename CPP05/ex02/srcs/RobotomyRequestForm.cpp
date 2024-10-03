#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45, "<target>")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called" <<  std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c) : AForm(c)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
	std::cout << "RobotomyRequestForm copy assignement called" << std::endl;
	if (this != &c)
		AForm::operator=(c);
	return *this;
}

void RobotomyRequestForm::task(Bureaucrat const &e) const
{
	std::cout << "*some drilling noises*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy on " << getTarget() << " failed." << std::endl;
}

