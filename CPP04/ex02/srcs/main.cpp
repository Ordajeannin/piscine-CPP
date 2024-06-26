#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int i = 15;
	Animal *animals[i];
//	Animal exemple = Animal();

	for (int j = 0; j < i; j += 2)
	{
		animals[j] = new Dog();
	}
	for (int j = 1; j < i; j += 2)
	{
		animals[j] = new Cat();
	}
	for (int j = 0; j < i; j++)
	{
		animals[j]->makeSound();
	}
	for (int j = 0; j < i; j++)
	{
		delete animals[j];
	}
	return 0;
}
