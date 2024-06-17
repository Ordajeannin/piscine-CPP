#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*messages[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*messages[i])();
			return;
		}
	}
	std::cout << "Unknown level: " << level << std::endl;
}

void Harl::filterComplaints(std::string level)
{
	enum Level { DEBUG, INFO, WARNING, ERROR, UNKNOWN };

	Level lvl = UNKNOWN;

	if (level == "DEBUG")
		lvl = DEBUG;
	else if (level == "INFO")
		lvl = INFO;
	else if (level == "WARNING")
		lvl = WARNING;
	else if (level == "ERROR")
		lvl = ERROR;

	switch (lvl)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			info();
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
	
