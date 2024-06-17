#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a"), b("b");

	a.attack(b);
	b.beRepaired(3);
	a.attack(b);
	a.attack(b);
	a.attack(b);
	return (0);
}
