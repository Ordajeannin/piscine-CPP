#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &c)
{
	*this = c;
}

RPN &RPN::operator=(const RPN &c)
{
	if (this != &c)
		_calculStr = c._calculStr;
	return *this;
}

RPN::~RPN() {}


/*
 * Prend une chaîne de caractères `calcuList` représentant une expression en RPN 
 * verifie:
 *	- que l'expression commence bien par deux nombres.
 * 	- que l'expression ne contient que des chiffres et des opérateurs valides (+, -, *, /).
 *	- que chaque élément est correctement séparé par un espace.
 *	- que le nombre d'opérateurs est exactement égal à `[nb - 1]`
*/
RPN::RPN(const std::string &calcuList) : _calculStr(calcuList)
{
	std::string goodChar = "1234567890+-/*";
	int nbNumber = 0;
	int nbOperator = 0;

	if (!isdigit(calcuList[0]) || calcuList[1] != ' ' || !isdigit(calcuList[2]))
		throw (RPN::BadRNPErrorException("must start with 2 numbers"));
	for (size_t i = 0; i < calcuList.length(); i ++)
	{
		for (size_t y = 0; y < goodChar.length(); y ++)
		{
			if (calcuList[i] == goodChar[y])
			{
				if (calcuList[i] >= '0' && calcuList[i] <= '9')
					nbNumber ++;
				else
					nbOperator ++;
				if (calcuList[i + 1] == ' ' || calcuList[i + 1] == 0)
					i ++;
				else
					throw (RPN::BadRNPErrorException("elements must be separated by space"));
				break;
			}
			else if (goodChar[y] == '*'/* && calcuList[i] != '*'*/)
				throw (RPN::BadRNPErrorException("only digits and operator are accepted"));
		}
	}
	if (nbNumber != (nbOperator + 1))
		throw (RPN::BadRNPErrorException("the number of operator must be [numbers - 1]"));
}

/*
 * Gere les operateur et les limites
*/
int doOperation(int a, int b, char calcOperator)
{
//	std::cout << a << calcOperator << b << "=";
	
	int result;
	switch (calcOperator)
	{
		case '+':
		{
			if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
				throw (RPN::BadRNPErrorException("overflowing int limit"));
			result = a + b;
			break;
		}
		case '-':
		{
			if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
				throw (RPN::BadRNPErrorException("overflowing int limit"));
			result = a - b;
			break;
		}
		case '*':
		{
			if (b != 0 && (a > INT_MAX / b || a < INT_MIN / b))
				throw (RPN::BadRNPErrorException("overflowing int limit"));
			result = a * b;
			
			break;
		}
		case '/':
		{
            if (b == 0)
                throw RPN::BadRNPErrorException("can't divide by 0");
            if (a == INT_MIN && b == -1)
                throw std::overflow_error("overflow during division");
			result = a / b;
			break;
		}
		default :
		{
			throw (RPN::BadRNPErrorException("operator error"));
		}
	}
	return result;
}

/*
 * Effectue le RPN avec une stack
 * 
 * parcours la str, puis
 *  - si chiffre, il est empile
 *  - si operateur, alors effectue l operation sur s-1 et s (dans cet ordre)
 *    -> empile le resultat
*/
void RPN::calcul(void)
{
	std::stack<int> stack;
	int tmp;
	int result;

	for (size_t i = 0; i < _calculStr.length(); i += 2)
	{
		if (isdigit(_calculStr[i]))
			stack.push(_calculStr[i] - '0');
		else
		{
			tmp = stack.top();
			stack.pop();

			result = doOperation(stack.top(), tmp, _calculStr[i]);
//			std::cout << result << std::endl;
			stack.pop();
			stack.push(result);
		}
	}
	std::cout << result << std::endl;
}

