#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	/*
    Bureaucrat 	obj1;
    Bureaucrat 	obj2("Boss", 1);
	Form		file1;
	Form		file2("Nuke", 150, 150);

	std::cout << std::endl;
	obj1.downGrade();
	obj1.upGrade();
	obj2.upGrade();
	obj2.downGrade();
	std::cout << std::endl;

	std::cout << obj1 << std::endl;
	std::cout << obj2 << std::endl;
	std::cout << std::endl;

	obj1.signForm(file1);
	*/
	Bureaucrat 	obj1("-random fonctionnaire-", 150);
	Bureaucrat 	obj2("-Boss-", 1);
	ShrubberyCreationForm	file1("<<precommande frites jeudi midi>>");
	RobotomyRequestForm		file2("<<Nuke>>");
	PresidentialPardonForm  file3("Paul");
	std::cout << std::endl;

	obj1.signForm(file1);
	obj1.signForm(file2);
	std::cout << std::endl;
	obj1.executeForm(file1);
	obj1.executeForm(file2);
	std::cout << std::endl;
	obj2.signForm(file1);
	obj2.signForm(file3);
	std::cout << std::endl;
	obj2.executeForm(file1);
	obj2.executeForm(file3);
	std::cout << std::endl;
    return 0;
}
