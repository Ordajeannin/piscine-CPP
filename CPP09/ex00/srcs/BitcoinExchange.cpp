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
			if (!isValidDate(date))
			{
				std::cerr << line << std::endl;
				break ;
			}
			double rate = atof(rateStr.c_str());
			exchangeRates[date] = rate;
		}
		else
		{
			std::cerr << "Error: database file in badformat => " << line << std::endl;
			return false;
		}
	}
	file.close();
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	std::istringstream ss(date);
	std::string yearStr, monthStr, dayStr;

	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int daysb[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr, ','))
	{
		int year = atoi(yearStr.c_str());
		int month = atoi(monthStr.c_str());
		int day = atoi(dayStr.c_str());

		if (month < 0 || month > 12)
		{
			std::cerr << "Error: month format incorrect => ";
			return false;
		}
		if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
		{
			if (day < 0 || day > days[month - 1])
			{
				std::cerr << "Error: classic year day format incorrect => ";
			}
		}
		else
		{
			if (day < 0 || day > daysb[month - 1])
				std::cerr << "Error: bissextile year day format incorrect => ";
		}
	}
	else
	{
		std::cerr << "Error: whole date format incorrect => ";
		return false;
	}
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
