#include <iostream>

using namespace std;

class A
{
private:

public:
    int value;
    ~A()
    {
        cout<<"Destructor of Class A is called "<<endl;
    }
    A() // Here the default constructor is already made although there was no need if we didn't have to use any constructor
    {
        cout<<"Constructor of Class A is called "<<endl;
    }
    void set_value(int data)
    {
        value = data ;
    }

};

class B :public A
{
private:

public:

    B()
    {
        cout<<"Constructor of Class B is called "<<endl<<endl;
    }
    ~B()
    {
        cout<<"Destructor of Class B is called "<<endl;
    }

};

int main()
{
    A obj1;
    //Here only constructor and destructor of A will run not B as it is a base class
    obj1.set_value(3);
    obj1.~A(); //Destructor called explicitly , doesn't do anything as it is a stack allocated object and still in the scope so obj1.value() is still fine
    cout<<endl<<endl <<"Value of star for object 1 : "<<obj1.value<<endl;
    //Only for dynamically allocated objects , we don't access their data after delete and nullptr


    //B obj2 ; ////Constructor of A will be called first , then constructor of B and Destructor of B will be called first , then Destructor of A

    return 0;
}




















