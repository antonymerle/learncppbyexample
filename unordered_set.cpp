#include <array>
#include <print>
#include <unordered_set>

void unordered_set()
{
    std::array numbers{1, 2, 42, 8, 0, -7, 2, 5, 10, 3, -100, 5};
    std::println("There are {} numbers in the original array.", numbers.size());

    std::unordered_set<int> unique_numbers;

    for (auto n : numbers) {
        unique_numbers.insert(n);
    }

    std::println("There are {} unique numbers in the set.", unique_numbers.size());

    std::unordered_set<std::string> planets{
        {"Venus"},
        {"Earth"},
        {"Mars"},
    };

    auto it = planets.find("Earth");
    if (it != planets.end()) {
        std::println("{}", *it);
    } else {
        std::println("No such planet");
    }

    it = planets.find("Tatooine");
    if (it != planets.end()) {
        std::println("{}", *it);
    } else {
        std::println("No such planet");
    }
}
