#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
    public:
        WrongAnimal();
		WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &c);
        virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &c);

		std::string getType() const;
		void makeSound() const;
};

#endif
