#include <iostream>

using namespace std;

class A     //This one will be Abstract Class (Interface Level)
{
public:
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
};
class B:public A    //This one will be an Adapter Class
{
public:
    //Contains all functions empty implementation so that it is Abstract no more
    void f1() override {}
    void f2() override {}
    void f3() override {}
    void f4() override {}
    void f5() override {}
    void f6() override {}

};
//Now write the class you want to use inherited from adapter class and implement any of the functions from above you want to and leave the rest as it is

// Step 3: The Actual Worker Class
// I only need f3(), so I don't have to waste time writing f1, f2, f4, f5, f6.
class MyWorker : public B
{
public:
    void f3() override
    {
        cout << "Only f3 is doing something useful here!" << endl;
    }
};

int main()
{
    return 0;
}
