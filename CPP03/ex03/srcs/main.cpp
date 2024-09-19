#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clap("a");
	ScavTrap scav("b");
	FragTrap frag("c");
	DiamondTrap diam("d");
	std::cout << std::endl;
    
	clap.attack(diam);
    clap.beRepaired(3);
	std::cout << std::endl;

    scav.attack(diam);
    scav.guardGate();
	std::cout << std::endl;

	frag.attack(diam);
	frag.highFivesGuys();
	std::cout << std::endl;

	diam.attack(clap);
	diam.whoAmI();
	diam.guardGate();
	diam.highFivesGuys();
	std::cout << std::endl;

    return 0;
}
