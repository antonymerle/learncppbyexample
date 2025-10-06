#include <iostream>
#include <string>

void convert_number_to_string()
{
    int i         = -100;
    std::string s = std::to_string(i);
    std::cout << s << "\n";

    // losing precision
    double pi      = 3.1415926535;
    std::string s2 = std::to_string(pi);
    std::cout << s2 << "\n";
}
