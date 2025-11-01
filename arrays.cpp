#include <array>
#include <iostream>
#include <unordered_set>

std::unordered_set<int> unique(const std::array<int, 12>& nums)
{
    std::unordered_set<int> set;
    for (const auto n : nums) {
        set.insert(n);
    }
    return set;
}

void arrays()
{
    std::array<int, 12> numbers{1, 2, 42, 8, 0, -7, 2, 5, 10, 3, -100, 5};

    std::unordered_set<int> set = unique(numbers);
    std::cout << "set size: " << set.size() << "\n";
}
