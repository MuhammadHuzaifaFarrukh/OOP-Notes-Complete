#include <iostream>
#include <iomanip>

using namespace std;

//Overloading () also called Functors if we are doing for calling functions

class A
{
private:
    int x;
public:
    A() {}
    A(int s)
    {
        x = s;
    }
    void operator()()
    {
        cout << "Function called with no arguments" << endl;
    }
    void operator()(int a)
    {
        cout << "Function called with argument: " << a << endl;
    }
    void operator()(int a, int b)
    {
        cout << "Function called with 2 arguments: " << a << " and " << b << endl;
    }
    int getdata()
    {
        return x;
    }
};

int main()
{
    A a1(5);
    a1();
    a1(10);
    a1(20, 30);

    return 0;
}
