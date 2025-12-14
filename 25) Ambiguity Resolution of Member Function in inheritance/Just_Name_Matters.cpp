#include <iostream>

using namespace std;

class Base
{
public:
    // Base class has a function that takes an integer
    void print(int i)
    {
        std::cout << "Base::print(int): " << i << std::endl;
    }

    // Base class has a function that takes no parameters
    void print()
    {
        std::cout << "Base::print()" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Derived class only has a function that takes a double
    //using Base::print;    //Writing this statement enables you to access any Base Class function without explicitly writing Base::func
    void print(double d)
    {
        //Either call those Base ones here
        std::cout << "Derived::print(double): " << d << std::endl;
    }
};

int main()
{
    Derived d;

    d.print(1.5); // ✅ OK: Calls Derived::print(double) because it matches the parameter.

    // d.print();    // ❌ ERROR: The compiler will stop here.
    // The derived class's print(double) hides *all* Base::print overloads,
    // including the perfect match Base::print().

    // d.print(10);  // ❌ ERROR: The compiler will stop here.
    // The derived class's print(double) hides Base::print(int), even though
    // 10 (int) can be implicitly converted to 1.5 (double). The hiding happens
    // before the conversion rules (overload resolution) are even checked.

    // To call the hidden base function, you must use the scope resolution operator:
    d.Base::print(10); // ✅ OK: Explicitly calls the hidden Base::print(int)
    d.Base::print();   // ✅ OK: Explicitly calls the hidden Base::print()

    return 0;
}
