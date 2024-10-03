#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &c);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &c);

		void task(Bureaucrat const &executor) const;
};

#endif
