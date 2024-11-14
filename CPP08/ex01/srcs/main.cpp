#include "Span.hpp"

int main() {
    Span obj1;
    Span obj2("example_name");
    Span obj3(obj2);

    obj1 = obj2;

    return 0;
}
