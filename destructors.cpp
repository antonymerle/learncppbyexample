#include <iostream>
#include <string>
#include <vector>

class Talker
{
   public:
    // Prefixing the explicit keyword to the constructor prevents the compiler from using that
    // constructor for implicit conversions.
    // https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
    explicit Talker(std::string name) : m_name{std::move(name)}
    {
        std::cout << m_name << " here\n";
    }
    ~Talker()
    {
        std::cout << m_name << " signing off\n";
    }

   private:
    std::string m_name;
};

void destructor()
{
    Talker antony("Antony");
    {
        std::vector<Talker> vec;
        vec.emplace_back("Manon");
    }
    Talker basile("Basile");

    // Manon signin off
    // Basile signin off
    // Antony signin off
}
