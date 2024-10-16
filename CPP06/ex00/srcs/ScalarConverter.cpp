#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

bool ScalarConverter::isInt(const std::string& str)
{
	char	*end;
	long	num = std::strtol(str.c_str(), &end, 10);

	return (*end == '\0'
			&& num >= std::numeric_limits<int>::min()
			&& num <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.lenght() = 3
			&& str[0] == '\''
			&& str[0] == '\'');
}

bool ScalarConverter::isFloat(const std::string& str)
{
	char	*end;
	float	num = std::strtof(str.c_str(), &end);

	return ((*end == 'f' || *end == '\0')
			&& num != HUGE_VALF);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char	*end;
	double	num = std::strtod(str.c_str(), &end);
	
	return (*end == '\0'
			&& num != HUGE_VAL);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isChar(literal))
	{
        char c = literal[1];
    
		std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
    }
    else if (isInt(literal))
	{
        int i = std::atoi(literal.c_str());
    
		if (i >= std::numeric_limits<char>::min()
				&& i <= std::numeric_limits<char>::max())
		{
            if (std::isprint(static_cast<char>(i)))
                std::cout << "char: '" << static_cast<char>(i) << "'\n";
            else
                std::cout << "char: Non displayable\n";
        }
		else
            std::cout << "char: impossible\n";

        std::cout << "int: " << i << "\n";
        std::cout << "float: " << static_cast<float>(i) << ".0f\n";
        std::cout << "double: " << static_cast<double>(i) << ".0\n";
    }
    else if (isFloat(literal))
	{
        float f = std::strtof(literal.c_str(), NULL);
        
		if (f >= std::numeric_limits<char>::min() 
				&& f <= std::numeric_limits<char>::max() 
				&& std::isprint(static_cast<char>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        else
            std::cout << "char: impossible\n";
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(f) << "\n";
		else
            std::cout << "int: impossible\n";
     
		std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
    }
    else if (isDouble(literal))
	{
        double d = std::strtod(literal.c_str(), NULL);

        if (d >= std::numeric_limits<char>::min()
				&& d <= std::numeric_limits<char>::max()
				&& std::isprint(static_cast<char>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: impossible\n";
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(d) << "\n";
        else
            std::cout << "int: impossible\n";
        
		std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << "\n";
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf"
			|| literal == "-inf" || literal == "+inf" || literal == "nan")
	{
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (literal.back() == 'f')
		{
            std::cout << "float: " << literal << "\n";
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
        } 
		else
		{
            std::cout << "float: " << literal << "f\n";
            std::cout << "double: " << literal << "\n";
        }
    }
    else 
        std::cout << "Invalid literal\n";
}
