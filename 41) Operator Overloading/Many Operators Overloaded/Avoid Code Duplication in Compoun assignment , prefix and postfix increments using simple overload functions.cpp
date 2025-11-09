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

    // + operator , use this in ++ prefix , postfix and compound assignment operators
    // To avoid code duplication only
    A operator+(const A& a1) const
    {
        return A(x + a1.x);
    }

    // Pre-increment ++a (using +)
    A& operator++()
    {
        *this = *this + A(1.0);
        return *this;
    }

    // Post-increment a++ (using +)
    A operator++(int)
    {
        A temp = *this;
        *this = *this + A(1.0);
        return temp;
    }

    // += operator (using +)
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
    ++a1;
    cout << "After ++a1: " << a1.getdata() << endl;

    // Post-increment
    cout << "After a1++: " << (a1++).getdata() << endl;
    cout << "a4 (result of a1++): " << a1.getdata() << endl;

    // += operator
    a1 += a2;
    cout << "After a1 += a2: " << a1.getdata() << endl;

    return 0;
}
