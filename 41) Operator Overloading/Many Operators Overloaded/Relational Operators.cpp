#include <iostream>
#include <iomanip>

using namespace std;

class A
{
private:
    double x;
public:
    A() {}
    A(double s)
    {
        x = s;
    }
    double getdata()const
    {
        return x;
    }
    //Can use getdata() instead of x or obj1.x
    bool operator<(const A& obj1)
    {
        return x < obj1.x;
    }

    bool operator>(const A& obj1)
    {
        return x > obj1.x;
    }

    bool operator<=(const A& obj1)
    {
        return x <= obj1.x;
    }

    bool operator>=(const A& obj1)
    {
        return x >= obj1.x;
    }

    bool operator==(const A& obj1)
    {
        return x == (obj1.x) ;
    }

};

int main()
{
    A a1(4), a2(5);
    cout << "Less than: " << (a1 < a2) << endl;
    cout << "Greater than: " << (a1 > a2) << endl;
    cout << "Less than or equal: " << (a1 <= a2) << endl;
    cout << "Greater than or equal: " << (a1 >= a2) << endl;
    cout << "Equal: " << (a1 == a2) << endl;

    return 0;
}
