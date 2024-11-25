#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->exchangeRates = other.exchangeRates;
	return *this;
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	//initialiser la map avec la base de donnee fournie
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			double rate = atof(rateStr.c_str());
			exchangeRates[date] = rate;
		}
	}
	file.close();
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	(void)date;
	return true;
}

double BitcoinExchange::getExchangeRate(const std::string &date)
{
	//extraire le exrate de la derniere date valable
	//-> input.txt
	if (!isValidDate(date))
		return -1.0;

	std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
	if (it != exchangeRates.end())
		return it->second;
	else
	{
		it = exchangeRates.lower_bound(date);
		if (it != exchangeRates.begin())
		{
			--it;
			return it->second;
		}
		else
			return -1.0;
	}
}
