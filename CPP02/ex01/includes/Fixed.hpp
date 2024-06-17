#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <climits>

class Fixed
{
	private:
		int _stock;
		const static int _coma = 8;

	public:
		Fixed();
		Fixed(const int nb);
		~Fixed();
		Fixed(const Fixed &copie);
		Fixed(const float nb);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
