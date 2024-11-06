#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

bool ScalarConverter::isInt(const std::string& str)
{
	char	*end;
	long	num = strtol(str.c_str(), &end, 10);

	return (*end == '\0'
			&& num >= std::numeric_limits<int>::min()
			&& num <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 3
			&& str[0] == '\''
			&& str[2] == '\'');
}

bool ScalarConverter::isFloat(const std::string& str)
{
	char	*end;
	float	num = strtof(str.c_str(), &end);

	return ((*end == 'f' || *end == '\0')
			&& num != HUGE_VALF);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char	*end;
	double	num = strtod(str.c_str(), &end);
	
	return (*end == '\0'
			&& num != HUGE_VAL);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isChar(literal))
	{
        char c = literal[1];
    
		std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isInt(literal))
	{
        int i = atoi(literal.c_str());
    
		if (i >= std::numeric_limits<char>::min()
				&& i <= std::numeric_limits<char>::max())
		{
            if (std::isprint(static_cast<char>(i)))
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
		else
            std::cout << "char: impossible" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    else if (isFloat(literal))
	{
        float f = strtof(literal.c_str(), NULL);
        
		if (f >= std::numeric_limits<char>::min() 
				&& f <= std::numeric_limits<char>::max() 
				&& std::isprint(static_cast<char>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
            std::cout << "int: impossible" << std::endl;
    
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(literal))
	{
        double d = strtod(literal.c_str(), NULL);

        if (d >= std::numeric_limits<char>::min()
				&& d <= std::numeric_limits<char>::max()
				&& std::isprint(static_cast<char>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf"
			|| literal == "-inf" || literal == "+inf" || literal == "nan")
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
		
		if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		{
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		}
		else
		{
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
    }
    else 
        std::cout << "Invalid literal" << std::endl;
}
