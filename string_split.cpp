#include <cstddef>
#include <iostream>
#include <string_view>
#include <vector>

std::vector<std::string_view> split(std::string_view str, char delim)
{
    std::vector<std::string_view> result;
    size_t begin = 0;

    while (begin < str.size()) {
        size_t end = str.find(delim, begin);

        if (end == std::string_view::npos) {
            result.push_back(str.substr(begin));
            break;
        }

        result.push_back(str.substr(begin, end - begin));
        begin = end + 1;
    }

    // handle the case where the string ends with delimiter
    if (begin == str.size() && !str.empty()) {
        result.push_back("");
    }

    return result;
}

void string_split()
{
    std::string planets{"Mercury,Venus,Earth,Mars"};
    std::cout << planets << "\n";

    std::cout << "--- Split on ',' ---\n";
    auto v = split(planets, ',');
    for (const auto& s : v) {
        std::cout << s << "\n";
    }

    std::cout << "--- Split on 'u' ---\n";
    v = split(planets, 'u');
    for (const auto& s : v) {
        std::cout << s << "\n";
    }

    std::cout << "--- Split on 'x' ---\n";
    v = split(planets, 'x');
    for (const auto& s : v) {
        std::cout << s << "\n";
    }

    std::cout << "--- Split an empty string ---\n";
    v = split("", ',');
    for (const auto& s : v) {
        std::cout << s << "\n";
    }
}
