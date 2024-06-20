#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &copie);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
