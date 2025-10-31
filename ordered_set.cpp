#include <iostream>
#include <set>
#include <string>

void ordered_set()
{
    std::set<std::string> fruits{{"banana"}, {"apple"}, {"orange"}, {"pear"}};

    for (const auto& fruit : fruits) {
        std::cout << fruit << "\n";
    }

    std::cout << "\nCustom comparator : shorter string first\n" << "\n";

    struct ShorterStringFirst {
        bool operator()(const std::string& a, const std::string& b) const
        {
            return a.size() < b.size();
        }
    };

    std::set<std::string, ShorterStringFirst> fruits2{
        {"banana"}, {"apple"}, {"cherries"}, {"pear"}};

    for (const auto& fruit : fruits2) {
        std::cout << fruit << "\n";
    }
}
