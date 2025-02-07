#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>

#define YES 1
#define NO 0

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dataBase;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &c);
		BitcoinExchange &operator=(const BitcoinExchange &c);
		~BitcoinExchange();

		void init(std::string databaseFilename);
		void calculRate(std::string inputFilename);

		class FileErrorException : public std::exception
		{
			private:
				std::string _message;

			public:
				FileErrorException(std::string message) : _message(message) {};
				virtual ~FileErrorException() throw() {};

				const char *what () const throw()
				{
					return (_message.c_str());
				}
		};
};

#endif
