#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("a");
	ClapTrap clap2("b");

	ScavTrap scav("c");
	ScavTrap scav2("d");

	ClapTrap clap3(clap);



	std::cout << std::endl;
    
	clap.attack(clap2);
    clap.beRepaired(3);
	clap2.beRepaired(3);
	std::cout << std::endl;

    scav.guardGate();
    scav2.attack(scav);
    
	std::cout << std::endl;
	scav.attack(clap);
	clap.attack(scav2);
	clap3.attack(scav2);
	std::cout << std::endl;
	
	std::cout << std::endl;

    return 0;
}
