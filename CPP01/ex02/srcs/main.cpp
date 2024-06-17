#include <string>
#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "adresse de str : " << &str << std::endl;
	std::cout << "adresse, stockee dans PTR : " << stringPTR << std::endl;
	std::cout << "adresse, stockee dans REF : " << &stringREF << std::endl << std::endl;

	std::cout << "valeur de str : " << str << std::endl;
	std::cout << "valeur pointee par PTR : " << *stringPTR << std::endl;
	std::cout << "valeur pointee par REF : " << stringREF << std::endl;

	return (0);
}
