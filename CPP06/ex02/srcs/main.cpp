#include "Base.hpp"

Base*	generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Creation of a A" << std::endl;
			return new A();
		case 1:
			std::cout << "Creation of a B" << std::endl;
			return new B();
		case 2:
			std::cout << "Creation of a C" << std::endl;
			return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "ptr : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr : C" << std::endl;
	else
		std::cout << "ptr unknown" << std::endl;
}

void	identify(Base& p)
{
	int i = 0;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "ref : A" << std::endl;
		i++;
	} catch (...) {};
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "ref : B" << std::endl;
		i++;
	} catch (...) {};

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "ref : C" << std::endl;
		i++;
	} catch (...) {};
	if (i == 0)
		std::cout << "ref unknown" << std::endl;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Base* basePtr = generate();
	std::cout << std::endl;

	std::cout << "Identification via pointer: " << std::endl;
	identify(basePtr);

	std::cout << "Identification via reference: " << std::endl;
	identify(*basePtr);

	delete basePtr;
    return 0;
}
