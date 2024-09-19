#include "ClapTrap.hpp"

int main()
{
	std::cout << std::endl << "Constructors called:" << std::endl;
	ClapTrap a("a"), b("b");
	ClapTrap c(a);
	std::cout << std::endl;

	a.attack(b);
	a.beRepaired(3);
	b.beRepaired(3);
	std::cout << std::endl;
	c.attack(a);
	a.attack(c);
	c.attack(b);
	std::cout << std::endl << "Destructors called:" << std::endl;
	return (0);
}
