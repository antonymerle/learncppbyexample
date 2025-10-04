#include <iostream>
#include <vector>

void add_vector()
{
    std::vector<int> v;
    v.push_back(777);
    v.push_back(42);

    std::cout << v.size() << "\n";
    std::cout << v.back() << "\n";

    v.pop_back();

    std::cout << v.size() << "\n";
    std::cout << v.back() << "\n";
}
