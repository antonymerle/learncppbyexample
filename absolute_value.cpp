#include <cmath>
#include <cstdlib>
#include <iostream>

void absolute_value()
{
    auto result = std::abs(-3.141592f);
    std::cout << result << "\n";
    auto result2 = std::abs(42);
    std::cout << result2 << "\n";
}
