#include <iostream>

template <typename T>
T cube(T t)
{
    return t * t * t;
}

struct Point {
    int x, y, z;

    friend Point operator*(const Point& a, const Point& b)
    {
        return Point(a.x * b.x, a.y * b.y, a.z * b.z);
    }
};

void templates()
{
    int x{7};
    std::cout << cube(x) << "\n";
    ;  // type inferred by compiler
    std::cout << cube<int>(x) << "\n";
    ;  // type manually specified

    float pi{3.14159f};
    std::cout << cube(pi);

    Point p{1, 2, 3};
    Point p2{cube(p)};
    std::cout << p2.x << ", " << p2.y << ", " << p2.z << "\n";
}
