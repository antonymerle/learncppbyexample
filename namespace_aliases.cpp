#include <iostream>
#include <ostream>

namespace ant_mathlib
{
template <typename T>
inline T add(T a, T b)
{
    return a + b;
}
}  // namespace ant_mathlib

// Create a namespace alias
namespace am = ant_mathlib;

void namespaces_aliases()
{
    // use namespace alias
    std::cout << am::add(3.1415, 42.0) << "\n";

    // or original namespace
    std::cout << ant_mathlib::add(2, 2) << "\n";
}
