#include <iostream>
#include <memory>

class Talker
{
   public:
    explicit Talker(std::string name) : name_{std::move(name)}
    {
        std::cout << name_ << " here.\n";
    };
    ~Talker()
    {
        std::cout << name_ << " signing out.\n";
    }

   private:
    std::string name_;
};

void smart_pointers()
{
    Talker* antony = new Talker{"Antony"};

    // std::unique_ptr calls delete automatically in their destructors
    std::unique_ptr<Talker> smart = std::make_unique<Talker>("Smart Joe");

    delete antony;
}
