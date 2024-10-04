#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public :
		Intern();
		~Intern();
		Intern &operator=(const Intern &c);

		AForm *makeForm(const std::string form, const std::string target) const;
};

#endif
