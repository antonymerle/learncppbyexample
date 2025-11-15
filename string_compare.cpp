#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string_view as_str(bool b)
{
    return b ? "true" : "false";
}

void string_compare()
{
    std::string s = "Christ is Lord";

    std::cout << (s == "Christ is Lord") << "\n";
    std::cout << as_str(s == "Christ is Lord") << "\n";

    std::vector<std::string_view> groups{"Genesis", "Boston", "ABBA", "Cream"};

    std::cout << as_str(groups[0] < groups[1]) << "\n";

    std::sort(groups.begin(), groups.end());
    for (auto g : groups) {
        std::cout << g << "\n";
    }
}
