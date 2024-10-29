#include "Array.hpp"

int main()
{
    // Test getSize //
    std::cout << "=== Test getSize ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "getSize : " << intArray.getSize() << std::endl;
	for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}
	std::cout << std::endl;

    // Test [] write //
    std::cout << "=== Test [] write ===" << std::endl;
    for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = i * 10;
	}
	std::cout << "(new values)" << std::endl << std::endl;
    
	// Test [] read //
	std::cout << "=== Test [] read ===" << std::endl;
    for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}
	std::cout << std::endl;

    // Test OutOfBoundsException //
    std::cout << "=== Test OutOfBoundsException ===" << std::endl;
    try
    {
        std::cout << "Acces a un index hors limite: " << intArray[10] << std::endl;
    }
    catch (const Array<int>::OutOfBoundsException& e)
    {
        std::cerr << "Exception catch: " << e.what() << std::endl;
    }

    // Array avec string
    std::cout << "\n=== Test Array<std::string> ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (unsigned int i = 0; i < stringArray.getSize(); ++i)
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    return 0;
}
