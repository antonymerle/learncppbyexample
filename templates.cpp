#include <cstddef>
#include <iostream>

template <typename T>
T cube(T t)
{
    return t * t * t;
}

template <typename T>
struct Point {
    T x, y, z;

    friend Point operator*(const Point& a, const Point& b)
    {
        return Point(a.x * b.x, a.y * b.y, a.z * b.z);
    }
};

template <typename T, size_t sz>
class Array
{
   public:
    T data_[sz];

    T& operator[](size_t i)
    {
        return data_[i];
    }

    T* begin()
    {
        return data_;
    }

    T* end()
    {
        return data_ + sz;
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
    std::cout << cube(pi) << "\n";
    ;

    Point p{1, 2, 3};
    Point p2{cube(p)};
    std::cout << p2.x << ", " << p2.y << ", " << p2.z << "\n";

    Point pf{1.33f, 2.33f, 3.33f};
    Point pf2{cube(pf)};
    std::cout << pf2.x << ", " << pf2.y << ", " << pf2.z << "\n";

    Array<int, 3> array{1, 2, 3};

    for (auto& it : array) {
        cube(it);
    }

    for (auto i = array.begin(); i < array.end(); ++i) {
        std::cout << *i << "\n";
    }

    std::cout << array.begin() << ", " << array[1] << ", " << array.end() << "\n";
}
