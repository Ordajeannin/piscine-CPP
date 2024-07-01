#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon pen = Weapon("stylo bic");
	HumanA jean("Jean Neige", pen);
	jean.attack();
	pen.setType("... something");
	jean.attack();
	
	Weapon plume = Weapon("stylo plume");
	HumanB john("John Snow");
	john.attack();
	
	john.setWeapon(plume);
	john.attack();
	plume.setType("... something");
	john.attack();
	
	return 0;
}
