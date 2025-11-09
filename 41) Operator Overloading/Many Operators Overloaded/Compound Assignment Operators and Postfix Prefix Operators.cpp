#include <iostream>
using namespace std;

class A
{
private:
    double x;
public:
    A(double s)
    {
        x = s;
    }

    // Pre-increment ++a
    A& operator++()
    {
        x += 1.0;
        return *this;
    }

    // Post-increment a++
    A operator++(int)
    {
        A temp = *this;
        x += 1.0;
        return temp;
    }

    // += operator
    A& operator+=(const A& obj)
    {
        x += obj.x;
        return *this;
    }

    double getdata() const
    {
        return x;
    }
};

int main()
{
    A a1(4.5);
    A a2(2.0);

    // Pre-increment
    cout << "Original a1: " << a1.getdata() << endl;
    A a3 = ++a1;
    cout << "After ++a1: " << a1.getdata() << endl;
    cout << "a3 (result of ++a1): " << a3.getdata() << endl;

    // Post-increment
    A a4 = a1++;
    cout << "After a1++: " << a1.getdata() << endl;
    cout << "a4 (result of a1++): " << a4.getdata() << endl;

    // += operator
    a1 += a2;
    cout << "After a1 += a2: " << a1.getdata() << endl;

    // Chaining +=
    A a5(1.0);
    a1 += a2 += a5;
    cout << "After chaining: a1 = " << a1.getdata() << endl;

    return 0;
}
