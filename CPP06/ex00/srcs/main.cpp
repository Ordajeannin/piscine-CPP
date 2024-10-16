#include "ScalarConverter.hpp"

int main() {
    ScalarConverter obj1;
    ScalarConverter obj2("example_name");
    ScalarConverter obj3(obj2);

    obj1 = obj2;

    return 0;
}
