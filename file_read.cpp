#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void file_read()
{
    std::ifstream input_fs{"guessing_game.cpp"};

    if (!input_fs.is_open()) {
        std::cerr << "Could not read file.\n";
    }

    std::vector<std::string> lines;
    for (std::string line; std::getline(input_fs, line);) {
        lines.push_back(std::move(line));
    }

    for (auto const& l : lines) {
        std::cout << l << "\n";
    }
}

void file_read2()
{
    std::string filename{"file_with_single_number.txt"};
    std::ifstream ifs{filename};

    if (!ifs.is_open()) std::cerr << "Cannot open file " << filename << "\n";

    int number = 0;
    std::cout << "number is " << number << "\n";

    std::cout << "Let's read from " << filename << "\n";
    ifs >> number;
    std::cout << "Now number is " << number << "\n";
}
