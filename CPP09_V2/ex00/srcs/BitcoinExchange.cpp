#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange created" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &c)
{
	*this = c;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &c)
{
	if (this != &c)
	{
		_dataBase = c._dataBase;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange deleted" << std::endl;
}


////////////////////////////////////////////////////////////////////////////////

void printMap(std::map<std::string, float> _dataBase)
{
	std::map<std::string, float>::iterator index = _dataBase.begin();

	for (; index != _dataBase.end(); index++)
	{
		std::cout << index->first << " | " << index->second << std::endl;
	}
}

std::string getDate(std::string line)
{
	std::string date = line.substr(0, 10);
	// std::cout << date << "\n";
	int daysList[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 7).c_str());
	int day = std::atoi(date.c_str() + 8);

	if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3])
		|| date[4] != '-' || !isdigit(date[5]) || !isdigit(date[6]) || date[7] != '-' 
		|| !isdigit(date[8]) || !isdigit(date[9]))
		throw (BitcoinExchange::FileErrorException("invalid date => " + date));
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		daysList[1] = 29;
	if (month < 1 || month > 12)
		throw (BitcoinExchange::FileErrorException("invalid date => " + date));
	if (day < 1 || day > daysList[month - 1])
		throw (BitcoinExchange::FileErrorException("invalid date => " + date));
	return date;
}

float checkFloatnb(std::string floatStr, int fromDatabase)
{
	float floatnb = std::atof(floatStr.c_str());
	bool decimal = false;

	for (size_t i = 0; i < floatStr.size(); i++)
	{
		if (i == 0 && floatStr[0] == '-')
			;
		else if (floatStr[i] == '.')
		{
			if (decimal == true)
				throw (BitcoinExchange::FileErrorException("non digit character found."));
			decimal = true;
		}
		else if (!isdigit(floatStr[i]))
			throw (BitcoinExchange::FileErrorException("non digit character found."));
	}
	if (fromDatabase == NO && (floatnb < 0 || floatnb > 1000))
		throw (BitcoinExchange::FileErrorException("number is or to large, or to small."));
	return floatnb;
}

std::pair<std::string, float> getPair(std::string line, int floatStart)
{
	if (line.length() < 12)
		throw (BitcoinExchange::FileErrorException("dataBase error"));

	std::string date;
	std::string floatStr = line.substr(floatStart, line.size());
	float floatnb;

	floatnb = checkFloatnb(floatStr, YES);
	date = getDate(line);
	return std::make_pair(date, floatnb);
}

float getPrice(std::string line)
{
	if (line.length() < 13)
		throw(BitcoinExchange::FileErrorException("bad input => " + line));
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw(BitcoinExchange::FileErrorException("bad input => " + line));
	std::string floatStr = line.substr(13, line.size());
	return checkFloatnb(floatStr, NO);
}

float getRate(std::map<std::string, float> &dataBase, std::string date)
{
	std::map<std::string, float>::iterator index = dataBase.lower_bound(date);

	if (index != dataBase.end() && index->first == date)
		return index->second;
	else if (index == dataBase.begin())
		throw(BitcoinExchange::FileErrorException("date not found"));
	else if (index == dataBase.end() || index->first > date)
	{
		index --;
		return index->second;
	}
	throw(BitcoinExchange::FileErrorException("date not found"));
}


////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::init(std::string databaseFilename)
{
	std::ifstream databaseStream(databaseFilename.c_str());
	std::string line;

	if (databaseStream.fail() || !databaseStream.is_open())
		std::cerr << "Error with file opening." << std::endl;

	std::getline(databaseStream, line);
	while(std::getline(databaseStream, line))
		_dataBase.insert(getPair(line, 11));
}

void BitcoinExchange::calculRate(std::string inputFilename)
{
	std::ifstream inputStream(inputFilename.c_str());
	std::string line;
	float price;
	float rate;
	std::string date;

	if (inputStream.fail() || !inputStream.is_open())
		std::cerr << "Error with file opening." << std::endl;
	std::getline(inputStream, line);
	while (std::getline(inputStream, line))
	{
		try
		{
			price = getPrice(line);
			date = getDate(line);
			rate = getRate(_dataBase, date);
			std::cout << date << " => " << price << " = " << price * rate << std::endl;
		}
		catch (const BitcoinExchange::FileErrorException &e)
		{
			std::cerr << "Error :" << e.what() << std::endl;
		}
	}
}
