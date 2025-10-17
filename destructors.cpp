#include <iostream>
#include <string>
#include <vector>

class Talker
{
   public:
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
}
