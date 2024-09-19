#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("a");
	ScavTrap scav("b");
	FragTrap frag("c");
	std::cout << std::endl;
    
	clap.attack(frag);
    frag.beRepaired(3);

	std::cout << std::endl;
	frag.attack(clap);
	frag.highFivesGuys();
    scav.attack(frag);
    scav.guardGate();
	std::cout << std::endl;
	frag.attack(clap);
	frag.highFivesGuys();
	std::cout << std::endl;

    return 0;
}
