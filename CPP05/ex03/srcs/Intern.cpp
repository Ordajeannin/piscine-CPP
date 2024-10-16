#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		std::cout << "Intern operator= overload called" << std::endl;
	return *this;
}

AForm *createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string formTarget) const
{
	const std::string formTypes[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*formCreators[])(const std::string&) = {
		&createShrubberyForm,
		&createRobotomyForm,
		&createPardonForm,
	};

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](formTarget);
		}
	}
	std::cout << std::endl << "Error: Form Type '" << formName << "' not found" << std::endl;
	std::cout << "List of forms available :" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << formTypes[i] << std::endl;
	}
	std::cout << std::endl;

	return NULL;
}
