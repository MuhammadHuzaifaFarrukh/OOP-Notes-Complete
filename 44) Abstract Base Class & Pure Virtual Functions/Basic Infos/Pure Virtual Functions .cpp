#include <iostream>

using namespace std;

//Pure Virtual Functions :
//You cannot create its object although pointer and references are allowed
//You should not define it , though if defined then no error
class Base
{
public:
    virtual void say() = 0;
};

void Base::say()
{
    cout<<"Say of Base "<<endl;
}

class Derived : public Base
{
public:
    void say()
    {
        cout<<"Say of Derived "<<endl;
    }
};


int main()
{
    Base *b1 = new Derived;
    b1->Base::say();    //Only works if Base::say() is defined
    b1->say();  //or b1->Derived::say();
    return 0;
}
