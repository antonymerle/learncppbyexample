#include <iostream>

/*
A class is used to describe a collection of data and functions that work well together. In C++ a
class’s data is known as its fields and a class’s functions are known as its methods. There’s two
keywords in C++ for declaring a class, class and struct. The only difference between the two is the
default access of members. class members are private by default and struct members are public.
Typically this means struct will be used for “plain old data” without any functions or private data
and class will be used for “objects” with methods, private data, and invariants. There really isn’t
any hard and fast rule though and everything a class can do a struct can do as well in C++.
*/

struct Affection {
    int rubs, pats, scritches = 0;
};

class Dog
{
   public:
    void pet(const Affection& affection)
    {
        happiness_ += 1 * affection.rubs;
        happiness_ += 2 * affection.pats;
        happiness_ += 3 * affection.scritches;
    }

    void bark() const noexcept
    {
        std::cout << (happiness_ <= 50 ? "woof" : "WOOF WOOF") << "\n";
    }

   private:
    int happiness_ = 40;
};

void classes()
{
    Dog dog;
    dog.bark();

    Affection affection;
    affection.rubs      = 2;
    affection.pats      = 4;
    affection.scritches = 3;
    dog.pet(affection);

    dog.bark();
}
