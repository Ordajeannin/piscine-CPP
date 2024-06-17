#ifndef HARLE_HPP
#define HARLE_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain(std::string level);
		void filterComplaints(std::string level);
};

#endif
