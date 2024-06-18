#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("a");
	ScavTrap scav("b");
	FragTrap frag("c");
	std::cout << std::endl;
    
	clap.attack(scav);
    clap.beRepaired(3);

    scav.attack(frag);
    scav.guardGate();

	frag.attack(clap);
	frag.highFivesGuys();
	std::cout << std::endl;

    return 0;
}
