#include <stack>

int main()
{
	std::stack<int> i;

	i.push_back(1);
	std::stack<int>::const_iterator it = i.begin();
	std::cout << *it;
	return 0;
}
