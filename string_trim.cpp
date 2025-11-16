#include <cstddef>
#include <iostream>
#include <string_view>

std::string_view trim(std::string_view s)
{
    // Whitespace is one of: space, tab, carriage return,
    // line feed, form feed, or vertical tab.
    std::string_view to_trim{" \t\n\r\f\v"};
    size_t begin = s.find_first_not_of(to_trim);
    if (begin == std::string::npos) return std::string_view{};

    size_t end = s.find_last_not_of(to_trim);

    return s.substr(begin, end - begin + 1);
}

void string_trim()
{
    std::string_view jupiter{"   Jupiter   "};
    jupiter = trim(jupiter);
    std::cout << jupiter << "\n";

    std::cout << trim(" \t\n\r\f\v") << "\n";

    std::string_view mars = trim("\tMars    \n");
    std::cout << mars;
}
