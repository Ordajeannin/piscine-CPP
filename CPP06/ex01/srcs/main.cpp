#include "Serializer.hpp"
#include <iostream>

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

    return 0;
}
