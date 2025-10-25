#include <print>
#include <string>
#include <utility>

void move_demo()
{
    std::string a{"hello"};
    std::string b{std::move(a)};

    /*
      b takes ownership of memory handle (pointer + sz)
      after that a is still valid, but unspecified (do not use)
    */

    std::println("a: \'{}\'", a);
    std::println("b: \'{}\'", b);

    /*
      a: ''
      b: 'hello'
    */
}
