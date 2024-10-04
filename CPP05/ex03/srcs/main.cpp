#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat 				obj1("-random fonctionnaire-", 140);
	Bureaucrat 				obj2("-Boss-", 1);
	ShrubberyCreationForm	file1("<<precommande frites jeudi midi>>");
	RobotomyRequestForm		file2("<<Nuke>>");
	PresidentialPardonForm  file3("Paul");
	std::cout << std::endl;

	obj1.signForm(file1);
	obj1.signForm(file2);
	obj1.signForm(file3);
	std::cout << std::endl;

	obj1.executeForm(file1);
	obj1.executeForm(file2);
	obj1.executeForm(file3);
	std::cout << std::endl;

	obj2.signForm(file1);
	obj2.signForm(file2);
	obj2.signForm(file3);
	std::cout << std::endl;

	obj2.executeForm(file1);
	obj2.executeForm(file2);
	obj2.executeForm(file3);
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
	{
		obj2.executeForm(file2);
	}
	std::cout << std::endl << std::endl;
    return 0;
}
