#include <iomanip>
#include <iostream>
#include <sstream>

/*
A stream is an abstraction that represents a sequence of data that flows from a source to a
destination. Think of it like a pipe where data flows through - you can read from it or write to it
sequentially. In C++, streams provide a uniform interface for I/O operations, whether you're working
with:

- Files (std::ifstream, std::ofstream)
- Strings (std::istringstream, std::ostringstream)
- Console (std::cin, std::cout)
- Network sockets
- Any other data source

Uniform Interface
You use the same operations (>>, <<, getline()) regardless of the data source

Streams buffer data, making I/O more efficient, especially for files

Use streams when:

- Parsing or tokenizing data
- Reading/writing files or I/O
- Converting between types
- Processing data sequentially

Use strings when:

- You need random access (str[5])
- Searching/replacing (str.find(), str.replace())
- You know the exact format and positions
- Simple concatenation
*/

void string_streams()
{
    // string parsing
    std::istringstream iss{"42 3.14 hello"};
    int i;
    double d;
    std::string s;
    iss >> i >> d >> s;  // Extracts: 42, 3.14, "hello"

    std::cout << i << "\n";
    std::cout << d << "\n";
    std::cout << s << "\n";

    // string building
    std::ostringstream oss;

    oss << "Value: " << 42 << ", Pi : " << 3.14;
    std::string result{oss.str()};
    std::cout << result << "\n";  // "Value: 42, Pi: 3.14"

    // Sequential processing
    std::istringstream is{"1 2 3"};
    int a, b, c;
    is >> a >> b >> c;  // Automatically advances position
    // No need to track indices like: str.substr(0,2), str.substr(3,5)...

    // Automatic type conversion
    std::string str{"42"};
    int manually_converted = std::stoi(str);
    std::cout << 42 - manually_converted << " equals 0" << "\n";

    std::istringstream in{"42"};
    int automatically_converted;

    in >> automatically_converted;
    std::cout << 42 - automatically_converted << " equals 0" << "\n";

    // Error Handling
    std::istringstream not_a_number{"zero"};
    int num;
    not_a_number >> num;
    if (not_a_number.fail()) {
        std::cerr << "Automatic string conversion failed" << "\n";
    }

    // formatted output

    std::ostringstream oss2;
    oss2 << std::setw(10) << std::setprecision(2) << 3.14159;
    std::cout << oss2.str() << "\n";
}
