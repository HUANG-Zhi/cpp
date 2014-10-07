#include <iostream>

template <class T>
T max(T& t1, T& t2)
{
    return t1 < t2 ? t2 : t1;
}

int main()
{
	int a = 33;
	int b = 44;
    std::cout << "Max of 33 and 44 is " << max(a, b) << std::endl;
    return 0;
}