#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
    private:
        ScalarConverter();
		static bool	isInt(const std::string& str);
		static bool isChar(const std::string& str);
		static bool	isFloat(const std::string& str);
		static bool	isDouble(const std::string& str);

    public:
		static void	convert(const std::string& literal);
};

#endif
