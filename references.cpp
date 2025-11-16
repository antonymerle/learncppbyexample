#include <iostream>

// References are aliases or “other names” for variables

void square(int& i)
{
    i *= i;
}

struct Point {
    int x, y;
};

void print_point(const Point& p) noexcept
{
    std::cout << p.x << ", " << p.y << "\n";
}

void references()
{
    int i = 2;

    int& i_alias = i;

    std::cout << "i : " << i << "\t" << "i_alias : " << i_alias << "\n";
    square(i);
    std::cout << "squaring i...\n";
    std::cout << "i : " << i << "\t" << "i_alias : " << i_alias << "\n";

    Point p{42, 42};

    Point& alias_p = p;

    p.x *= 2;
    p.y *= 2;

    print_point(alias_p);
}
