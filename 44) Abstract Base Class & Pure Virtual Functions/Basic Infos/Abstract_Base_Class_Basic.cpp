#include <iostream>

using namespace std;

class Base
{
public:
    //Base class is the Abstract Base Class , containing pure virtual functions
    //Any class that contains at least one Pure Virtual Function is called Abstract Base Class
    //You cannot instantiate it
    //You may make its pointer / Reference though
    virtual void say() = 0;
    virtual void hello() = 0;

    virtual void show() //Non-Pure Member / Non-Pure Virtual Function
    {
        //Anything to show
    }
};

class Derived : public Base
{
public:
    //Still an abstract class as it contains no definition of the function hello()
    //You still cannot make its object
    void say()
    {
        cout<<"Say"<<endl;
    }
};

class Derived2 : public Derived
{

public:
    //Now its a non-abstract base class or concrete class
    //It can be instantiated
    void hello()
    {
        cout<<"Hello"<<endl;
    }
};
int main()
{
    Derived2 d1;

    return 0;
}
