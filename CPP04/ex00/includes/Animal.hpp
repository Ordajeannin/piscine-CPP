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
		Animal(std::string type);
        Animal(const Animal &c);
        virtual ~Animal();
		Animal &operator=(const Animal &c);

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
