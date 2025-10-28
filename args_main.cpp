#include <print>

int args_main(int argc, char* argv[])
{
    if (argc > 0) {
        std::println("Hello from {}", argv[0]);
    }
    if (argc > 1) {
        std::println("The first argument is {}", argv[1]);
    }
    return 0;
}
