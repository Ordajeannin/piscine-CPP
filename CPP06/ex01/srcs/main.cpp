#include "Serializer.hpp"
#include <iostream>

void printBinary(int value)
{
	std::cout << ((value >> 31) & 1) << " ";

	for (int i = 30; i >= 23; --i)
	{
		std::cout << ((value >> i) & 1);
	}
	std::cout << " ";

	for (int i = 22; i >= 0; --i)
	{
		std::cout << ((value >> i) & 1);
	}
	std::cout << std::endl;
}

int main()
{
	Data pos;
	pos.x = 4;
	pos.y = 2;

	uintptr_t raw = Serializer::serialize(&pos);
	Data* posPtr = Serializer::deserialize(raw);

	if (posPtr == &pos)
	{
		std::cout << "Serialization and deserialization seems to work :)" << std::endl;
		std::cout << "following posPtr:" << std::endl;
		std::cout << "Pos x: " << posPtr->x << std::endl;
		std::cout << "Pos y: " << posPtr->y << std::endl;
	}
	else
		std::cout << "... Fichtre" << std::endl;

	{
		std::cout << std::endl << "let's play un peu" << std::endl;
		float pi = 3.14f;
		int* intPtr = reinterpret_cast<int*>(&pi);
		int rawFloat = *intPtr;

		int sign = (rawFloat >> 31) & 1;
		int exponent = (rawFloat >> 23) & 0xFF;
		int mantisse = rawFloat & 0x7FFFFF;

		std::cout << "Valeur Float : " << pi << std::endl;
		std::cout << "interpretation int : " << rawFloat << std::endl;
		std::cout << "Binaire en memoire : ";
		printBinary(rawFloat);
		std::cout << "Signe : " << sign << std::endl;
		std::cout << "Exponent : " << exponent << std::endl;
		std::cout << "Mantisse : " << mantisse << std::endl;
		//mantisseReel = 1 + (mantisseBinaire / 2^23)
		std::cout << "Calc : (-1)^" << sign << " x " << (1.0f + ((float)mantisse / (float)8388608)) << " x 2^" << exponent - 127;
		std::cout << std::endl;
	}

    return 0;
}
