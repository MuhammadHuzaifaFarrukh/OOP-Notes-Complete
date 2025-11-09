#include <iostream>
#include <iomanip>

using namespace std;

class A
{
private:
    bool x;
public:
    A() {}
    A(bool s)
    {
        x = s;
    }

    bool getdata() const
    {
        return x;
    }
    //Can use getdata() instead of x or obj1.x
    bool operator&&(const A& obj1)
    {
        return x && obj1.x;
    }

    bool operator||(const A& obj1)
    {
        return x || obj1.x;
    }

    bool operator!()
    {
        return !x;
    }

};

int main()
{
    A a1(true), a2(false);
    A a3(0) , a4(1);
    cout << "Logical AND: " << (a1 && a2) << endl;
    cout << "Logical OR: " << (a1 || a2) << endl;
    cout << "Logical NOT: " << (!a3) << endl;

    return 0;
}
