#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
using namespace std;

//We throw exception inside a constructor to check if its given inputs are correct or not.
//We may do this in member initialization list , or inside constructor's body
//Here we show in constructor's body :
//B's constructor throws an exception which is caught inside main
//Now when exception is thrown , B's constructor doesn't run fully
//As a result B object is not made completely , so destructor for B's member var that were initialized runs (not shown even if we write)
//and any Base classes / Composition Objects destructor run (which are shown if written)
//Then we catch the exception and inside main and the catch block is executed

class A
{
public:
    A()
    {
        cout<<"A's constructor"<<endl;
    }
    void show()
    {
        cout<<"Show from A" <<endl;
    }
    ~A()
    {
        cout<<"A's destructor "<<endl;
    }
};

class B : public A
{
public:
    B() //May write : A()
    {
        cout<<"Constructor of B "<<endl;
        throw runtime_error("Not Good");
    }
    ~B()
    {
        cout<<"Destructor of B"<<endl;
    }
    void show_B()
    {
        cout<<"Show from B"<<endl;
    }
};

int main()
{
    try
    {
        B b1;
        b1.show_B();
    }
    catch(exception &e)
    {
        cout<<e.what();
    }

    return 0;
}
