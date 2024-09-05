#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
        Animal();
		Animal(std::string type);
        Animal(const Animal &c);
    public:
        virtual ~Animal();
		Animal &operator=(const Animal &c);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
