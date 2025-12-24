#include <iostream>

class B
{
public:
    void sayHello()
    {
        std::cout << "Hello from B!" << std::endl;
    }
};

class A
{
private:
    B* b_ptr; // Aggregation via Pointer

public:
    // Method 1: Member Initializer List (Preferred)
    A(B* object) : b_ptr(object)
    {
        std::cout << "A constructed with pointer." << std::endl;
    }

    // Method 2: Inside Constructor Body (Also valid for pointers)
    /*
    A(B* object) {
        b_ptr = object;
    }
    */

    void useB()
    {
        if (b_ptr != nullptr)   // Safety check
        {
            b_ptr->sayHello();
        }
    }
};

int main()
{
    B myB;       // B exists independently 
    A myA(&myB); // A aggregates B (Stack Allocated Object B)
    myA.useB();
    return 0;
}
