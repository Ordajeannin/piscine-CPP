#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("a");
	ClapTrap clap2("b");
	ScavTrap scav("c");
	ScavTrap scav2("d");
	std::cout << std::endl;
    
	clap.attack(clap2);
    clap.beRepaired(3);

    scav.attack(clap);
    scav.guardGate();

    scav2.attack(scav);
	std::cout << std::endl;

    return 0;
}
