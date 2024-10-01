#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj1;
    Bureaucrat obj2("Boss", 1);
//    Bureaucrat obj3("God", 0);
//    Bureaucrat obj4("Juste une pierre sur son chemin", 151);

	std::cout << std::endl;
	obj1.downGrade();
	obj1.upGrade();
	obj2.upGrade();
	obj2.downGrade();
	std::cout << std::endl;

	std::cout << obj1 << std::endl;
	std::cout << obj2 << std::endl;

    return 0;
}
