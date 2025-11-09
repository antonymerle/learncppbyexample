#include <algorithm>
#include <cstddef>
#include <format>
#include <functional>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>

/*
sort takes three parameters: the start of a sequence to sort, the end of the same sequence, and the
“compare operation” to perform when sorting. By default the compare operation is the less than
operator (<) which will sort items in ascending order.
*/
void classic()
{
    std::cout << "default -- ascending order\n";
    std::vector nums{20, 20, 1, 8, 18, 4, 19, 15, 5, 2};
    std::sort(nums.begin(), nums.end());
    for (const int& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    int c_array[] = {20, 20, 1, 8, 18, 4, 19, 15, 5, 2};
    std::sort(std::begin(c_array), std::end(c_array));
    for (const int& n : c_array) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";
}

void greater()
{
    std::cout << "descending order\n";

    std::vector nums{20, 20, 1, 8, 18, 4, 19, 15, 5, 2};

    for (const int& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (const int& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";
}

void subrange()
{
    std::cout << "sort sub range (first half, decreasing)\n";

    std::vector nums{20, 20, 1, 8, 18, 4, 19, 15, 5, 2};

    for (const int& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    auto midpoint = nums.begin() + (nums.size() / 2);

    std::sort(nums.begin(), midpoint, std::greater<int>());
    for (const int& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";
}

template <typename T>
void print_vec(const std::vector<T>& v)
{
    std::cout << "{ ";
    for (const auto& item : v) {
        std::cout << item << " ";
    }
    std::cout << "}";
}

// The compare function is a function that accepts two arguments and returns true
// if the first parameter should be ordered before the second.
void custom_compare()
{
    std::cout << "custom compare function\n";
    std::vector nums{20, 20, 1, 8, 18, 4, 19, 15, 5, 2};
    print_vec(nums);
    std::cout << "\n";
    std::sort(nums.begin(), nums.end(),
              [](const auto& a, const auto& _) -> bool { return a % 2 == 0; });
    print_vec(nums);
    std::cout << "\n\n";
}

// lexicographic sorting
void str_sort()
{
    std::cout << "lexicographic sorting -- default\n";
    std::vector<std::string> famille{"Antony", "Manon", "Basile", "Irène", "Andreï"};
    std::sort(famille.begin(), famille.end());
    print_vec(famille);
    std::cout << "\n\n";
}

size_t utf8_length(const std::string& s)
{
    size_t length = 0;
    for (size_t i = 0; i < s.size();) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c < 0x80)
            i += 1;  // 1-byte character (ASCII)
        else if (c < 0xE0)
            i += 2;  // 2-byte character
        else if (c < 0xF0)
            i += 3;  // 3-byte character
        else
            i += 4;  // 4-byte character
        length++;
    }
    return length;
}

// sort strings by length
void str_sort_custom()
{
    std::cout << "custom string compare function -- by length\n";
    std::vector<std::string> famille{"Antony", "Manon", "Basile", "Irène", "Andreï"};
    std::sort(famille.begin(), famille.end(),
              [](const auto& a, const auto& b) { return utf8_length(a) < utf8_length(b); });
    print_vec(famille);
    std::cout << "\n\n";
}

void sort()
{
    classic();
    greater();
    subrange();
    custom_compare();
    str_sort();
    str_sort_custom();
}
