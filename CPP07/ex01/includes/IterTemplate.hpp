#ifndef ITERTEMPLATE
#define ITERTEMPLATE

template <typename T, typename F>
void iter(T *array, int length, F fonction)
{
	for (int i = 0; i < length; i++)
	{
		fonction(array[i]);
	}
}

#endif
