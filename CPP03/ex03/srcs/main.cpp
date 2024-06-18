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
    
	clap.attack(scav);
    clap.beRepaired(3);

    scav.attack(frag);
    scav.guardGate();

	frag.attack(clap);
	frag.highFivesGuys();

	diam.attack(clap);
	diam.whoAmI();
	std::cout << std::endl;

    return 0;
}
