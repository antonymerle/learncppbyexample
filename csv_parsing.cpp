#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void csv_parsing()
{
    std::string filename{"planets.csv"};
    std::ifstream input{filename};

    if (!input.is_open()) {
        std::cerr << "Error opening file : " << filename << "\n";
        return;
    }

    std::vector<std::vector<std::string>> csv_rows;

    for (std::string line; std::getline(input, line);) {
        std::istringstream ss{std::move(line)};
        std::vector<std::string> row;  // temporary, to me moved in csv_rows later

        // check if csv_rows is empty, if not, allocate memory based on first row sz
        if (!csv_rows.empty()) {
            row.reserve(csv_rows.front().size());
        }

        for (std::string value; std::getline(ss, value, ',');) {
            row.push_back(std::move(value));
        }
        csv_rows.push_back(std::move(row));
    }

    // print out the table
    for (const auto& csv_row : csv_rows) {
        for (const auto& val : csv_row) {
            std::cout << std::setw(10) << val;
        }
        std::cout << '\n';
    }
}
