#include <iostream>
using namespace std;

class A
{
private:
    int x;
public:
    A() {}
    A(int s) : x(s) {}

    // Dereference operator *
    int& operator*()
    {
        return x;
    }

    // Arrow operator ->
    A* operator->()
    {
        return this;
    }

    int getdata()
    {
        return x;
    }
};

int main()
{
    A a1(5);
    cout << "Dereference: " << *a1 << endl;
    cout << "Arrow: " << a1->getdata() << endl;

    *a1 = 15;
    cout << "Modified Value: " << *a1 << endl;

    //The Call *a1 becomes : (a1.operator*())
    //The Call a1->getdata() becomes : (a1->operator())->getdata()

    return 0;
}
