#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "-------------------- PART ONE -----------------------" << std::endl;
{
	int i = 6;
	int n = 0;
	Animal *animals[i];

	for (int j = 0; j < i; j++)
	{
		if (j % 2 == 0)
			animals[j] = new Dog();
		else
			animals[j] = new Cat();
	}
	std::cout << std::endl;
	while (n < i)
		animals[n++]->makeSound();
	std::cout << std::endl;
	for (int j = 0; j < i; j++)
	{
		delete animals[j];
	}
	std::cout << std::endl;
}
std::cout << "-------------------- PART TWO -----------------------" << std::endl;
{
	Dog a;
	Cat b;
	Animal c;
	{
		std::cout << std::endl;
		Dog d = a;
		Cat e = b;
		Animal f = c;
		std::cout << std::endl;
		d.makeSound();
		e.makeSound();
		f.makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	c.makeSound();
	std::cout << std::endl;
}
	return 0;
}
/*
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
}*/
