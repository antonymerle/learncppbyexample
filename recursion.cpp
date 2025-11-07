#include <sys/types.h>

#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>

// The factorial of N is N * N-1 * N-2 ... * 1
// 7! = 7 * 6 * 5 * 4 * 3 * 2 * 1
uint64_t factorial(uint64_t n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    std::cout << n << "\n";
    return n * factorial(n - 1);
}

std::string lol(uint64_t n, std::string str)
{
    if (n == 0 || n == 1) return str;

    str += "ha";
    return lol(n - 1, str);
}

// Calculate the Nth fibonacci number where 0 is the 0th number
// The Fibonacci rule is the Nth number is equal to the sum of the
// previous two numbers, so N = (N-1) + (N-2)
// The first two numbers should be 0 and 1
// The first 8 Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13

uint64_t fib(uint64_t n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

void recursion()
{
    std::cout << factorial(7) << "\n";
    std::cout << lol(1, "ha") << "\n";
    std::cout << fib(7) << "\n";
}

/*
  The stack is FILO (First In, Last Out), or more commonly called LIFO (Last In, First Out).

  ==== 1. Stack building (first in) ====
  | factorial(1) |  ← Last call pushed (TOP)
  | factorial(2) |
  | factorial(3) |
  | factorial(4) |
  | factorial(5) |
  | factorial(6) |
  | factorial(7) |  ← First call pushed (BOTTOM)
    +==============+

  ==== 2. Stack unwinding (last out) ====
  factorial(1) returns 1               ← Resolves FIRST (was last in)
  factorial(2) gets 1, returns 2
  factorial(3) gets 2, returns 6
  factorial(4) gets 6, returns 24
  factorial(5) gets 24, returns 120
  factorial(6) gets 120, returns 720
  factorial(7) gets 720, returns 5040  ← Resolves LAST (was first in)

*/
