#include <iostream>
#include <vector>

void vector_add()
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
