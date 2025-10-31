#include <cmath>
#include <iostream>

void nearest_integer()
{
    // The ceil function returns the smallest integer that is not less than its argument.

    std::cout << "ceiling" << "\n";
    int ceiling = static_cast<int>(std::ceil(3.141592f));  // 4
    std::cout << ceiling << "\n";
    std::cout << std::ceil(-3.141592f) << "\n";  // -3

    // The floor function returns the largest integer that is not greater than its argument.
    std::cout << "floor" << "\n";
    int floor = static_cast<int>(std::floor(3.141592f));  // 3
    std::cout << floor << "\n";
    std::cout << std::floor(-3.141592f) << "\n";  // -4

    // The trunc function returns the nearest integer to its argument by removing
    // the decimal portion of the argument.

    std::cout << "trunc" << "\n";
    int trunc = static_cast<int>(std::trunc(3.141592f));  // 3
    std::cout << trunc << "\n";
    std::cout << std::trunc(-3.141592f) << "\n";  // -3

    // The round function returns the nearest integer to its argument.
    // When the argument is halfway between two integers (.5) the value is rounded away from zero.

    std::cout << "round" << "\n";
    int round = static_cast<int>(std::round(3.141592f));  // 3
    std::cout << round << "\n";
    std::cout << std::round(-3.141592f) << "\n";  // -3
    std::cout << std::round(3.5) << "\n";         // 4
}
