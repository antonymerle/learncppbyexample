#include <iostream>
#include <ostream>

// automating manual memory management (not calling manually new/delete)

class HeapInt
{
   public:
    explicit HeapInt(int i) : m_heap_int{new int{i}}
    {
        std::cout << "new int" << "\n";
    }

    ~HeapInt()
    {
        delete m_heap_int;
        std::cout << "delete int" << "\n";
    }

    inline int value()
    {
        return *m_heap_int;
    }

    inline auto address()
    {
        return &m_heap_int;
    }

   private:
    int* m_heap_int;
};

void heap()
{
    int* heap_created = new int{42};
    std::cout << "heap_created address on the heap : " << &heap_created << "\n";
    delete heap_created;

    // auto mode with destructors
    HeapInt a(5);
    std::cout << "a.value(): " << a.value() << "\n";
    std::cout << "a.address(): " << a.address() << "\n";

    {
        HeapInt b(7);
        std::cout << "b.value(): " << b.value() << "\n";
        std::cout << "b.address(): " << b.address() << "\n";
    }
}
