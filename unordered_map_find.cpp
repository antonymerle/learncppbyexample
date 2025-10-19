#include <print>
#include <string>
#include <unordered_map>

void hash_map_find()
{
    std::unordered_map<int, std::string> statusCodes{{200, "Success"},   {201, "Created"},
                                                     {202, "Accepted"},  {400, "Bad request"},
                                                     {403, "Forbidden"}, {404, "Not Found"}};

    auto iterator = statusCodes.find(200);
    if (iterator == statusCodes.end()) {
        std::println("No such status code...");
    } else {
        std::println("{} status code means : {}", iterator->first, iterator->second);
    }

    int code       = 1000;
    auto iterator2 = statusCodes.find(code);
    if (iterator2 == statusCodes.end()) {
        std::println("{} : No such status code...", code);
    } else {
        std::println("{} status code means : {}", iterator2->first, iterator2->second);
    }

    statusCodes.insert({500, "Internal server error"});

    std::println("500 means {}", statusCodes[500]);
    statusCodes[800] = "Oops, I meant 500, now we have a new entry with a key and and empty value";
    std::println("800 means {}", statusCodes[800]);

    // Oops, we have a new entry with a key and empty value
    std::string description = statusCodes[1000];
    std::println("Description is empty : {}", statusCodes[1000]);
}
