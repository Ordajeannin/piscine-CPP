#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj1;
    Bureaucrat obj2("example_name", 1);
    Bureaucrat obj3(obj2);

    obj1 = obj2;

    return 0;
}
