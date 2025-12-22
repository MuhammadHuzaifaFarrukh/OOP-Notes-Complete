#include <iostream>
#include<string>

using namespace std;

//Using const ensures no data member is changed inside the function
//Using mutable for some data members , this specialty of const does not work as they can be changed now

class Example
{
private:
    mutable int cache;        // Can be modified in const functions
    int normalVar;           // Cannot be modified in const functions

public:
    Example() : cache(0), normalVar(0) {}

    // Const member function
    int getValue() const
    {
        cache++;  // ✅ Allowed because cache is mutable
        // normalVar++;  // ❌ Compile error - can't modify in const function
        return cache;
    }

    void setNormal(int x)
    {
        normalVar = x;  // ✅ Allowed in non-const function
    }
};

int main()
{
    //We can also make const objects but then we have to use constructor to initialize every data member of that object
    //And we won't be able to reinitialize again the data members as the object is constant
    //Can only set or reinitialize the mutable data members

    return 0;
}



//These const and mutable are very helpful when we make an object using const keyword like : const Example e1;
//Now its data can't be changed and it can also not call any member functions of its own that are non-constant
//It will only call constant functions and data can be changed using mutable keyword , in this way we strictly ensure which data to change and which to not
//Also we can have two functions with same name but one being non-const and other const after function ()
