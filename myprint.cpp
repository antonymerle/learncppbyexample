#include <iostream>

template <typename... Args>
void my_print(const Args&... args)
{
    (std::cout << ... << args);
}
template <typename... Args>
void my_println(const Args&... args)
{
    (std::cout << ... << args) << "\n";
}

void test_my_print()
{
    std::string name{"Antony"};
    int age = 42;
    my_println("Hi my name is ", name, " and I am ", age);
}
