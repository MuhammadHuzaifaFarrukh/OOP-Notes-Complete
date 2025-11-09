#include <iostream>
#include <iomanip>

using namespace std;

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

    int getdata() const
    {
        return x;
    }
    //Can use getdata() instead of x or obj1.x
    A operator&(const A& obj1)
    {
        int t = x & obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }
    A operator|(const A& obj1)
    {
        int t = x | obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator~()
    {
        int t = ~x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator<<(const A& obj1)
    {
        int t = x << obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator>>(const A& obj1)
    {
        int t = x >> obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

};

int main()
{
    A a1(4), a2(5);
    A a3 = a1 & a2;
    A a4 = a1 | a2;
    A a5 = ~a1;
    A a6 = a1 << a2;
    A a7 = a1 >> a2;
    cout << "Bitwise AND: " << a3.getdata() << endl;
    cout << "Bitwise OR: " << a4.getdata() << endl;
    cout << "Bitwise NOT: " << a5.getdata() << endl;
    cout << "Left Shift: " << a6.getdata() << endl;
    cout << "Right Shift: " << a7.getdata() << endl;

    return 0;
}
