#include <iostream>

using namespace std;

//Lvalue & Rvalue :

//In int x = 10 , x is lvalue and 10 is rvalue
//lvalue has a name , label and stored for later use , its reference is represented as & sign
//rvalue does not have a name , temporary , its reference is represented as && sign

//int&& ref = 10;	OK as 10 is an Rvalue. int&& is specifically designed to bind to it.
//int x = 10; int&& ref = x;	ERROR as x is an Lvalue. int&& cannot bind to a named Lvalue. The compiler prevents you from accidentally moving from an object you might still need.


//Move Constructor :
//A move constructor is a special constructor in C++ that lets us transfer the contents of one
//object to another without copying the data. It is useful for performance - it's faster than copying.

//Syntax :
/*
className&& is an rvalue reference to another object of the same class.
The double ampersand && is key: it allows the function to bind to temporary (rvalue) objects.
The other object is the source from the resource will be moved, not copied.
*/


class A
{
private:
    int* ptr;

public:
    // Constructor
    A(int value)
    {
        // Dynamically allocate memory
        ptr = new int(value);
        cout << "Constructor called\n";
    }

    // Move Constructor
    A(A&& obj) //Don't use const , as this function is used by a non-constant object for which data is being moved so its contents will need to be changed , if we wrote const here , then it would also allow const objects to work but it would then behave differently as const objects cannot be changed but we are stealing and changing resources allowing Undefined Behaviour
    {
        cout << "Move Constructor called\n";
        // Steal the pointer
        ptr = obj.ptr;
        //This line moves all data

        obj.ptr = nullptr; // and then obj.ptr points to nothing , but can be given new value or used for other purpose
    }

    // Destructor
    ~A()
    {
        if (ptr != nullptr)
        {
            cout << "Destructor deleting data: " << *ptr << endl;
        }
        else
        {
            cout << "Destructor called on nullptr\n";
        }
        delete ptr;
    }

    // Display function
    void display()
    {
        if (ptr)
            cout << "Value: " << *ptr << endl;
        else
            cout << "No data\n";
    }
};

int main()
{
    // Constructor is called
    A obj1(42);
    // Move constructor is called
    //1.
    A obj2 = move(obj1); // or use std::move
    //Even though obj1 is lvalue , we cast it into rvalue so we can move its contents into obj2
    //move simply casts the lvalue to rvalue
    //When compiler sees this value being converted it checks :
    //it checks its overloads and selects the Move Constructor (A(A&&)) because it's the best match for the Rvalue.

    // 2. Direct initialization
    //A obj2(std::move(obj1));


    cout << "\nAfter move:\n";
    cout << "obj1: ";
    // Should show "No data"
    obj1.display();
    cout << "obj2: ";
    // Should show "Value: 42"
    obj2.display();

    return 0;
}


//Move Constructor for  More Members (By using Member initialization list):
 /*
 A(A&& other) noexcept

        // Initialize members by stealing 'other's resources and values

        // Member initializer list is the preferred way:

        : a(other.a), // Steal the pointer (ownership transfer)

          b(other.b), // Simple member copy (or move, but same result for float)

          d(other.d)  // Simple member copy
*/







//If you make any constructor from either copy / move , then compiler won't make any constructor whether its copy or move
//If you make any assignment operator , then compiler won't make any assignment opperator whether its copy or move
//If you make any destructor then compiler won't make that for you


