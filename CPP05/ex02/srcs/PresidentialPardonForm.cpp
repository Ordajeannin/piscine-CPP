#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5, "<target>")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called" <<  std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c) : AForm(c)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
	std::cout << "PresidentialPardonForm copy assignement called" << std::endl;
	if (this != &c)
		AForm::operator=(c);
	return *this;
}

void PresidentialPardonForm::task(Bureaucrat const &e) const
{
	std::cout << e.getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
