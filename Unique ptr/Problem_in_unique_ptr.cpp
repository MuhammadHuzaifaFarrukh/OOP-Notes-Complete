#include <iostream>
#include <memory>

int main()
{
    //In Normal Pointers we could easily do :
    // int *x,*y ;
    // x = new int(10);
    // y =x;
    //However this is forbidden in smart pointer unique_ptr
    //Two ways to solve this :

    //One is this : (By transferring the ownership using move() )
    std::unique_ptr<int> x = std::make_unique<int>(10);

    // std::unique_ptr<int> y = x; // ERROR! This won't compile.

    std::unique_ptr<int> y = std::move(x); // SUCCESS!

    // Now:
    // y owns the memory (value 10)
    // x is now null (empty)

    if (x == nullptr)
    {
        std::cout << "x is now empty." << std::endl;
    }
    std::cout << "y now owns the value: " << *y << std::endl;



    //Second Way is using shared_ptr which can be inefficient for more ownerships sharing :
    // 1. Create a shared pointer
    std::shared_ptr<int> ptr_x = std::make_shared<int>(10);

    // 2. Simply assign it to y (This is allowed here!)
    std::shared_ptr<int> ptr_y = x;

    // Both now point to the same address
    std::cout << "Value via x: " << *ptr_x << " at address: " << ptr_x.get() << std::endl;
    std::cout << "Value via y: " << *ptr_y << " at address: " << ptr_y.get() << std::endl;

    // 3. See the reference count
    std::cout << "Ownership count: " << ptr_x.use_count() << std::endl; // Prints 2
}
