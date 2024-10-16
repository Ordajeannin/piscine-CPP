#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	God("Neuro-Chirurgien", 1);
	Intern 		carabin;
	AForm*		f1;
	AForm*		f2;
	AForm*		f3;
	AForm*		bourragePapier;
	std::cout << std::endl;

	f1 = carabin.makeForm("shrubbery creation", "grass");
	f2 = carabin.makeForm("robotomy request", "the intern");
	f3 = carabin.makeForm("presidential pardon", "Pr. Sorbier");
	bourragePapier = carabin.makeForm("augmentation de salaire", "moi");
	std::cout << std::endl;

	God.signForm(*f1);
	God.signForm(*f2);
	God.signForm(*f3);
	std::cout << std::endl;

	God.executeForm(*f1);
	God.executeForm(*f2);
	God.executeForm(*f3);
	std::cout << std::endl;

	delete f1;
	delete f2;
	delete f3;
	delete bourragePapier;
	return 0;
}
