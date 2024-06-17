#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int _stock;
		const static int coma = 8;

	public:
		Fixed(int nb = 0);
		~Fixed();
		Fixed(const Fixed &copie);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
