#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
	private :
		std::map<std::string, double> exchangeRates;
		bool isValidDate(const std::string &date);

	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);

		bool loadDatabase(const std::string &filename);
		double getExchangeRate(const std::string &date);
};

#endif
