#include <iostream>

template <typename T>
T square(T n)
{
    return n * n;
}

void square()
{
    std::cout << square(2) << "\n";
    std::cout << square(2.0f) << "\n";
}
