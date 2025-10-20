#include <print>
#include <random>

/*
C++ does not provide a simple “random” function, instead the C++ Standard Library provides three
distinct components we must assemble to generate random numbers:

1. “random device”. These are intended to be implemented by the hardware your program is running on
to provide non-deterministic random numbers.

2.  “random number engine”. These are large state
machines that generate pseudo-random numbers. 3

3. “random distribution”. These are lightweight
functions that map an input number to a predetermined range of possible outputs.
*/

void random_run()
{
    // 1. The random device
    std::random_device rd;

    // 2. The "Mersenne Twister" random engine
    std::mt19937 gen(rd());

    // 3. A random distribution
    std::uniform_int_distribution<int> dist(1, 20);

    for (size_t i = 0; i < 10; ++i) {
        std::print("{} ", dist(gen));
    }
    std::println();

    std::println("sizeof rd : {} bytes", sizeof(rd));
    std::println("sizeof gen : {} bytes", sizeof(gen));
    std::println("sizeof dist : {} bytes", sizeof(dist));
}
