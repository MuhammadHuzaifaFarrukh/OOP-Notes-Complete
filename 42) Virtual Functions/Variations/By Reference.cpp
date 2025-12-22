#include <iostream>

using namespace std;

class Base
{
public:
    virtual void greet() const
    {
        std::cout << "Base greeting!\n";
    }
    // Note: The destructor should also be virtual in a polymorphic base class
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void greet() const override
    {
        std::cout << "Derived special greeting!\n";
    }
};

void call_greeting(Base& obj)
{
    // Because 'obj' is a reference to Base, and 'greet' is virtual,
    // the call is dynamically dispatched based on the actual object type.
    obj.greet();
}

int main()
{
    Derived d;

    // Create a reference to the Base class, referencing the Derived object
    Base& ref_to_derived = d;
    Base b;
    // 1. Direct call via the reference
    ref_to_derived.greet(); // Output: Derived special greeting!

    //call_greeting(b);     //Calls Base one as Base Object Passed
    // 2. Call via a function that accepts a Base reference
    call_greeting(d);       // Output: Derived special greeting!
    //Can be done using Pointers as we did here with References
    //Can be done with Pure Virtual Functions also
    return 0;
}
