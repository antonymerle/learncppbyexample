#include <iostream>

int multiply_pointers(const int* a, const int* b)
{
    return *a * *b;
}

int multiply_refs(const int& a, const int& b)
{
    return a * b;
}

void pointers()
{
    int answer = 42;
    int* pt    = &answer;

    std::cout << "pointer dereferencing : " << *pt << "\n";
    std::cout << "pointer's adress : " << &pt << "\n";

    int zero = 0;

    std::cout << multiply_pointers(&answer, &zero) << "\n";
    std::cout << multiply_refs(answer, zero) << "\n";
}
