#include <fstream>

void file_creation()
{
    std::ofstream output{"ofstream_example.txt"};
    output << "Glory to God!\n";

    output << 777;
}
