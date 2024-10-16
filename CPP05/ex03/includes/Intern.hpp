#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &c);

		AForm *makeForm(const std::string formName, const std::string formTarget) const;
};

#endif
