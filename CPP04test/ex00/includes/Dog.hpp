#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string _name;
		const std::string _type;

    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog &c);
        ~Dog();
		
		void makeSound() const;
};

#endif
