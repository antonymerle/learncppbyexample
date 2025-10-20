#include <map>
#include <print>

void for_loop()
{
    std::map<std::string, float> fruit_prices{
        {"Apple", 0.69f},
        {"Banana", 0.87f},
        {"Orange", 1.1f},
    };

    for (auto [fruit, price] : fruit_prices) {
        std::println("{} costs {}$", fruit, price);
    }
}
