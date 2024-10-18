#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
	int	x;
	int y;
};

class Serializer
{
    private:
        Serializer();
    public:
		static uintptr_t 	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
