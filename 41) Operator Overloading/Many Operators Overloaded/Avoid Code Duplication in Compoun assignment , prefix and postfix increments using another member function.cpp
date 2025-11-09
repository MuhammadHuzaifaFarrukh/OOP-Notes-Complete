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

    // + operator
    A operator+(const A& a1) const
    {
        return A(x + a1.x);
    }

    // Common increment function
    void increment()
    {
        *this = *this + A(1.0);
    }

    // Pre-increment ++a
    A& operator++()
    {
        increment();
        return *this;
    }

    // Post-increment a++
    A operator++(int)
    {
        A temp = *this;
        increment();
        return temp;
    }

    // += operator
    A& operator+=(const A& obj)
    {
        *this = *this + obj;
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

    return 0;
}
