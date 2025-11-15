#include <cstddef>
#include <iostream>
#include <string_view>

template <typename T>
auto mid_point(const T& t)
{
    auto midpoint = t.begin() + (t.size() / 2);
    return *midpoint;
}

void string_length()
{
    std::string_view s{"Bayonne"};
    std::cout << s.length() << "\n";
    std::cout << s.size() << "\n";

    std::cout << mid_point(s) << "\n";

    std::string_view utf8{"สวัสดีจ้า"};

    // All of the containers in C++’s Standard Library provide a size() method which returns the
    // number of elements in the container.
    // std::vector, std::map, std::stack, std::string...
    size_t sz = utf8.size();
    size_t l  = utf8.length();

    std::cout << utf8 << " size in bytes is " << sz << "\n";
    std::cout << utf8 << " length in bytes is " << l << "\n";
}
