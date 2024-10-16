#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <cctypes>

class ScalarConverter
{
    private:
        ScalarConverter();
		static bool	isInt(const std::string& str);
		static bool isChar(const std::string& str);
		static bool	isFloat(const std::string& str);
		static bool	isDouble(const std::string& str);

    public:
		static void	converter(const std::string& literal);
};

#endif
