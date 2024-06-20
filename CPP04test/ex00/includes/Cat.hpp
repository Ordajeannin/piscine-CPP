#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
		std::string _name;
	    const std::string _type;

    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat &c);
        ~Cat();

		void makeSound() const;
};

#endif
