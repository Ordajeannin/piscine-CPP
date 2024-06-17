#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

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
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const; 
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
