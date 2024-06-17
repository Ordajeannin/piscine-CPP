#include "Zombie.hpp"

int main()
{
	std::cout << "JE SUIS DANS LE MAIN" << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << "JE SORS DU MAIN, je vais dans newZombie" << std::endl;
	Zombie *exemple = newZombie("fenetre");
	std::cout << "JE SUIS DE RETOUR DANS LE MAIN" << std::endl;
	exemple->announce();
	std::cout << "Je le re-rebute" << std::endl;
	delete exemple;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << "JE SORS DU MAIN, je vais dans randomChump" << std::endl;
	randomChump("volets");
	std::cout << "JE SUIS DE RETOUR DANS LE MAIN" << std::endl;
	return (0);
}
