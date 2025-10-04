#include <iostream>
#include <string>

void string_append()
{
    std::string sentence{"She"};
    sentence.append(" is playing");
    sentence += " the piano.";

    std::cout << sentence << "\n";
}
