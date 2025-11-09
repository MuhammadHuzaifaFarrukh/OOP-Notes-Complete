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
        A temp = *this;
        for(int i = 0; i < a1.x; i++)
        {
            temp.increment();
        }
        return temp;
    }
    // Common increment function
    void increment()
    {
        x += 1.0;
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

    A a3  = a1+a2;
    cout << " a1 + a2 : " << a3.getdata() << endl;

    return 0;
}
