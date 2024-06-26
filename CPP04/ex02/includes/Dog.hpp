#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
    public:
        Dog();
        Dog(const Dog &c);
        ~Dog();
		Dog &operator=(const Dog &c);

		void makeSound() const;
};

#endif
