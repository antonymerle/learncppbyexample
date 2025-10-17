#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>

class bad_divide : public std::domain_error
{
   public:
    bad_divide(const char* what, const float dividend, const float divisor)
        : std::domain_error(what), dividend{dividend}, divisor{divisor}
    {
    }
    float dividend;
    float divisor;
};

float strict_divide(const float dividend, const float divisor)
{
    if (!std::isfinite(dividend)) {
        throw std::out_of_range("Dividend must be finite!");
    } else if (!std::isnormal(divisor)) {
        throw std::invalid_argument("Divisor ain't normal!");
    }
    return dividend / divisor;
}

float custom_strict_divide(const float dividend, const float divisor)
{
    if (!std::isfinite(dividend)) {
        throw bad_divide("Dividend must be finite!", dividend, divisor);
    } else if (!std::isnormal(divisor)) {
        throw bad_divide("Divisor ain't normal!", dividend, divisor);
    }
    return dividend / divisor;
}

void exceptions()
{
    try {
        strict_divide(42, 0);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        strict_divide(INFINITY, 2.2f);
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    } catch (...) {
        std::cout << "Something went wrong...\n";
    }

    try {
        custom_strict_divide(42, 0);
    } catch (bad_divide& e) {
        std::cout << e.what() << ": " << e.dividend << "/" << e.divisor << "\n";
    }
}
