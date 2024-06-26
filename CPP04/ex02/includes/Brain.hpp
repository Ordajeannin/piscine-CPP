#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &c);
        ~Brain();
		Brain &operator=(const Brain &c);

		std::string getIdea(int index) const;
		void setIdea(int index , const std::string &idea);
};

#endif
