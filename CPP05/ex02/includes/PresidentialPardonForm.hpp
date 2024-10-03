#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &c);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &c);

		void task(Bureaucrat const &executor) const;
};

#endif
