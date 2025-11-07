#include <iostream>
#include <string>

#include "header.h"

class Person
{
   public:
    explicit Person(int age) : m_age{age} {};

    void birthday()
    {
        m_age++;
        std::cout << "It's " << m_nickname << "'s birthday.\n";
        std::cout << "You're " << m_age << ". Have anything to say?\n";
        std::cout << "\"" << m_catchphrase << "\"\n";
    }

    std::string m_nickname;

    // code outside the class cannot access protected fields
    // but the class itself and subclasses can access protected fields.
   protected:
    std::string m_catchphrase{"Que sera sera."};

   private:
    int m_age;
};

class Kid : public Person
{
   public:
    explicit Kid(int age) : Person{age}
    {
        m_catchphrase = "I am a kid.";
    };
};

void access_modifiers()
{
    Person person(42);
    person.m_nickname = "Antony";
    person.birthday();

    Kid kid{8};
    kid.m_nickname = "Basile";
    kid.birthday();
}
