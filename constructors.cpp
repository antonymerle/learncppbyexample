#include <stdio.h>

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

class File
{
   public:
    File(const std::string& path, const std::string& mode)
    {
        file_ = fopen(path.c_str(), mode.c_str());
        if (!file_) {
            throw std::runtime_error("Failed to open " + path + " with mode " + mode);
        }
    }
    ~File()
    {
        fclose(file_);
    }

   private:
    FILE* file_;
};

void constructor()
{
    try {
        File file("some_nonexisting_path", "r");
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
}
