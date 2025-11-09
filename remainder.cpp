#include <cmath>
#include <iostream>

void remainder()
{
    auto remi = 23 % 5;
    auto remf = std::fmod(23.4f, 5.0f);

    std::cout << remi << "\n";
    std::cout << remf << "\n";
}
