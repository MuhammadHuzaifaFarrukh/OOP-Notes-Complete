#include <iostream>

using namespace std;

//Virtual Destructor :
//The primary reason to use a virtual destructor, even without virtual functions,
//is to ensure proper cleanup when deleting objects through a base class pointer.

//The Virtual Destructor is also in vtable
//Even if a class has no virtual functions, the presence of a virtual destructor alone is
//enough to require the compiler to generate and use a VTable (Virtual Table) for that class.

//USES :
// 1) Rule of Thumb:
//"If you have any virtual functions, you probably need a virtual destructor"

// 2) The Golden Rule:
//If you EVER delete through a base pointer (delete base_ptr), you NEED a virtual destructor
//in the base class - regardless of dynamic memory!
//Although works fine in this case (where no dynamic alloc) but good practice to use it even here in this case

// 3) If we have dynamic allocations and we are using inheritance and using base ptr to point derived obj

// Explained simple (uses) :
// Polymorphic Deletion ,  Class has virtual methods
// Base Class Manages Resources (Dynamically allocated members in Inheritance) Baseptr -> Derived Obj
// In inheritance (not even when dynamic allocation occurs) and Baseptr->Derived Obj as Derived Class destructor is never called


//NOT NEEDED FOR :
// 1)No Inheritance -> No Polymorphism
// 2)Using pointers of same class to allocate memory (Inheritance or not)


//Performance Overhead :
//The presence of a virtual destructor adds a hidden pointer (vptr) to every object of the
//class. This increases the size of every object and adds a small cost to
//construction/destruction by initializing the vptr.


class A
{
public :
    int a =3;
    A()
    {
        std::cout<<"Constructor of Base class was called "<<endl;
    }
    //virtual ~Base() = default;  // Clear intent, compiler-generated
    //You can ask the compiler to generate a Virtual Destructor for you
    virtual ~A()
    {
        std::cout<<"Destructor of Base class was called "<<endl;
    }
};

class B : public A
{
public :
    int b=5;
    B()
    {
        std::cout<<"Constructor of derived class was called "<<endl;
    }
    ~B()  // Automatically virtual because base destructor is virtual
    {
        std::cout<<"Destructor of derived class was called "<<endl;
    }
};


//When you call delete ptr;, the runtime system uses the vptr in the Derived object to look
//up the correct destructor's address in the VTable. This ensures:
//The Derived destructor is called first.
//The Base destructor is called second.






int main()
{
    A * ptrA = new B;
    delete ptrA;
    // ptrA = nullptr; //Not necessary


    return 0;
}



//Although we use virtual destructors while using virtual functions , they can be used even when we don't use virtual functions
//Example where no virtual destructor leaks memory :
/*
class Base
{
public:
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base
{
private:
    int* data;
public:
    Derived()
    {
        data = new int[100];
    }

    ~Derived()
    {
        delete[] data;  // This won't be called!
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    Base* ptr = new Derived();
    delete ptr;  // MEMORY LEAK! Only Base destructor called
    // Output: "Base destructor"
    // Derived destructor NOT called → data[] not deleted!
}
*/


//If the base destructor were not virtual, delete ptr; would only call the Base destructor,
//leading to a memory leak because the Derived part of the object would not be properly
// cleaned up.

//Detailed Explanation :
/*
What happens step-by-step:
1) delete ptr is called

2) Compiler checks destructor type:

Is Base::~Base() virtual? ✅ YES

3) Look up vtable:

Follow the vptr in the object pointed to by ptr

The object is actually a Derived object, and it contains a virtual destructor so its vtable has Derived::~Derived

4) Call through vtable:

Call Derived::~Derived() first

Then automatically call Base::~Base() (compiler ensures this)
*/

//Key Rules :
//Declare in base class
//All derived destructors automatically become virtual
//Declare virtual destructor in the base class whenever you have polymorphic inheritance - regardless of where the dynamic data lives. This ensures the entire destruction chain happens correctly.
