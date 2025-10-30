#include <print>
#include <string>

// Const Member Functions
class Dog
{
   public:
    void set_name(std::string name)
    {
        m_name = std::move(name);
    }

    const std::string& get_name() const
    {
        return m_name;
    }

   private:
    std::string m_name;
};

// Static Member Functions

class Cat
{
   public:
    Cat()
    {
        cat_count++;
    }

    ~Cat()
    {
        cat_count--;
    }

    void set_name(std::string name)
    {
        this->name = std::move(name);
    }

    const std::string& get_name() const
    {
        return name;
    }

    static int get_count()
    {
        return cat_count;
    }

   private:
    std::string name;
    static int cat_count;
};

// Static class data must be initialized out-of-line

int Cat::cat_count = 0;

/* Virtual Member FunctionsV
   Virtual member functions enable polymorphism in C++.
   Virtual member functions in base classes can be
   overridden in derived classes by using the override keyword.
   Virtual member functions can be const just like regular member functions.
   When a const virtual member function is overridden the override
   must also be const.

 */

class Animal
{
   public:
    virtual int get_legs_number() const
    {
        return 0;
    }
    virtual ~Animal() {};
};

class Cow : public Animal
{
   public:
    void set_name(std::string name)
    {
        this->name = std::move(name);
    }

    const std::string& get_name() const
    {
        return name;
    }

    int get_legs_number() const override
    {
        return 4;
    }

   private:
    std::string name;
};

class Centipede : public Animal
{
   public:
    int get_legs_number() const override
    {
        return 100;
    }
};

void member_functions()
{
    Dog d;
    d.set_name("fido");

    std::string name = d.get_name();

    std::println("The dog is named {}.", name);

    Cat cat;
    cat.set_name("Felix");
    std::println("There is {} cat whose name is {}", cat.get_count(), cat.get_name());

    Cat cat2;
    cat2.set_name("Cannelle");
    std::println("There are {} cats, {} and {}", cat.get_count(), cat.get_name(), cat2.get_name());
    Cow cow;
    std::println("The cow has {} legs.", cow.get_legs_number());

    Centipede centipede;
    std::println("The centipede has {} legs.", centipede.get_legs_number());
}
