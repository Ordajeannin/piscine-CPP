#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
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
    return 0;
}
