#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

void convert_string_to_number()
{
    std::string s{"-100"};
    int i = std::stoi(s);
    std::cout << i << "\n";

    std::string s2{"    -2025     "};
    long l = std::stol(s2);
    std::cout << l << "\n";

    std::string s3{"64600 Anglet"};
    unsigned long ul = std::stoul(s3);
    std::cout << ul << "\n";

    std::string s4{"3.1415926535"};
    float f = std::stof(s4);
    std::cout << f << "\n";

    std::string s5{"9.10938356e-31kg"};
    double mass_of_electron = std::stof(s5);
    std::cout << mass_of_electron << "\n";

    std::string s6{"0123a45"};
    size_t pos = 0;
    int i6     = std::stoi(s6, &pos, 10);
    std::cout << "on " + s6 + " string, stoi stopped parsing at position " << pos
              << " and resulted in " << i6 << "\n";

    // Binary for 64000  and extra words that won't be processed
    std::string s7 = "1111110001011000 is the postal code of my city.";
    size_t position;
    int i7 = std::stoi(s7, &position, 2);

    std::string remainder = s7.substr(position);

    std::cout << i7 << remainder << "\n";

    // exceptions
    std::string s8{"this is not parsable as an int 123"};
    try {
        int i8 = std::stoi(s8);
        std::cout << i8 << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    std::string s9 = "9999999999999";
    try {
        int i8 = std::stoi(s9);
        std::cout << i8 << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }
}
