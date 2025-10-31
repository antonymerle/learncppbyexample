#include <functional>
#include <iostream>
#include <map>
#include <string>

/*
std::map is a key-value container that maintains its keys in sorted order at all times. Generally
std::map is implemented as a tree of key-value pairs, and not a hash map. This means when iterating
the key-value pairs of a std::map the order will always be known but that insertion or lookup
(search) is slower than std::unordered_map.
*/

void unordered_map()
{
    // default behaviour : alphabetically sorted with std::less<Key>
    std::cout << "sorted by default : std::less\n";
    std::map<std::string, int> family{
        {"Antony", 42}, {"Manon", 38}, {"Basile", 8}, {"Irène", 3}, {"Andreï", 3}};

    for (const auto& [name, age] : family) {
        std::cout << name << " is " << age << " old" << "\n";
    }
    /*
      Andreï is 3 old
      Antony is 42 old
      Basile is 8 old
      Irène is 3 old
      Manon is 38 old
     */

    std::cout << "\nsorted by age\n";
    std::map<int, std::string, std::greater_equal<>> family_reversed_sorted_by_age{
        {42, "Antony"}, {38, "Manon"}, {8, "Basile"}, {3, "Irène"}, {3, "Andreï"}};

    for (const auto& [age, name] : family_reversed_sorted_by_age) {
        std::cout << name << " is " << age << " old" << "\n";
    }

    std::cout << "\ncustom comparator : string sz\n";
    // provide a custom comparator but can only operate on keys
    struct ShorterString {
        bool operator()(const std::string& a, const std::string& b) const
        {
            return a.size() <= b.size();
        }
    };

    std::map<std::string, int, ShorterString> family2{
        {"Antony", 42}, {"Manon", 38}, {"Basile", 8}, {"Irène", 3}, {"Andreï", 3}};

    for (const auto& [name, age] : family2) {
        std::cout << name << " is " << age << " old" << "\n";
    }
}
