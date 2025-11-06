#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T>& v)
{
    o << "[";
    if (v.empty()) {
        o << "]";
    }

    // print each element with a trailing comma, except the last one
    for (auto item = v.begin(); item != --v.end(); item++) {
        o << *item << ", ";
    }
    o << v.back() << "]";
    return o;
}

template <typename KeyT, typename ValueT>
std::ostream& operator<<(std::ostream& o, std::map<KeyT, ValueT>& m)
{
    if (m.empty()) {
        o << "{}";
        return o;
    }
    o << "{";
    for (const auto& [k, v] : m) {
        o << " key: " << k << ", value: " << v;
    }
    o << "}";
    return o;
}

void container_print()
{
    std::vector<std::string> famille{"Antony", "Manon", "Basile", "Irène", "Andreï"};
    std::cout << famille << "\n";

    std::vector<int> prime{2, 3, 5, 7, 11};
    std::cout << prime << "\n";

    std::map<std::string, float> planet_distances{
        {"Venus", 0.723f},
        {"Earth", 1.0f},
        {"Mars", 1.5f},
    };

    std::cout << planet_distances << "\n";
};
