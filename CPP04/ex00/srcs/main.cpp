#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "---------- TESTS CLASSIQUES -----------" << std::endl;
	Cat a;
	Dog b;
	Animal c;
	std::cout << std::endl;

	std::cout << a.getType() << " " << std::endl;
	std::cout << b.getType() << " " << std::endl;
	std::cout << c.getType() << " " << std::endl;
	std::cout << std::endl;

	a.makeSound();
	b.makeSound();
	c.makeSound();
	std::cout << std::endl;
	}	

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "----------- TESTS POINTEURS ALLOUES ----------" << std::endl;
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----------- TESTS WRONG POINTEURS ----------" << std::endl;
	const WrongAnimal *wi = new WrongCat();
	const WrongAnimal *wmeta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << wi->getType() << " " << std::endl;
	std::cout << std::endl;

	wi->makeSound();
	wmeta->makeSound();
	std::cout << std::endl;

	delete wi;
	delete wmeta;
	return 0;
}
