#include <iostream>
#include <string>
#include <unordered_map>

struct Planet {
    std::string name;

    friend bool operator==(const Planet& a, const Planet& b)
    {
        return a.name == b.name;
    }
};

// Our custom std::hash specialization for Planet
template <>
struct std::hash<Planet> {
    size_t operator()(const Planet& p) const noexcept
    {
        return std::hash<std::string>{}(p.name);
    }
};

void unordered_map_custom_type()
{
    std::unordered_map<Planet, std::string> descriptions{
        {{"Earth"}, "Home"},
        {{"Mars"}, "The red planet"},
    };

    Planet earth{"Earth"};
    descriptions[earth] = "Maison";
    std::cout << descriptions[earth] << "\n";
}
