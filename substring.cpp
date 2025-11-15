#include <cstddef>
#include <iostream>
#include <string_view>

void substring()
{
    std::string_view planets{"Mercury Venus Earth Mars"};

    // Copy 5 characters from position 8
    std::cout << planets.substr(8, 5) << "\n";

    size_t begin{planets.find("Earth")};
    std::cout << planets.substr(begin);
}
