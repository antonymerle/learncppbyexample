#include <print>

struct Point {
    int x;
    int y;
};

void struct_fn()
{
    Point p = {};
    std::println("x = {} and y = {}", p.x, p.y);
}
