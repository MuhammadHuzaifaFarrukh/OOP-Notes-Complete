#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
using namespace std;

//We throw exception inside a constructor to check if its given inputs are correct or not.
//We may do this in member initialization list , or inside constructor's body
//Here we show in constructor's body :
//B's constructor throws an exception which is caught inside B's constructor
//Now that this exception is caught , B's constructor runs completely
//Hence B object is completed
//Now inside main , we can work with B object as we want and destructor orders are just like as usual (normal)
//A destructor runs and then B's

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
        try
        {
            throw runtime_error("Not Good");
        }
        catch(exception &e)
        {
            cout<<e.what();
        }
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
    B b1;
    b1.show();


    return 0;
}
