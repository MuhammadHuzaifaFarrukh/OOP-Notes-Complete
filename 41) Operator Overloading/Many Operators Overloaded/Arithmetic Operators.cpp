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
    double getdata() const
    {
        return x;
    }
    //Can use getdata() instead of x or obj1.x

    A operator+(const A& obj1)
    {
        double t = x+obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator-(const A& obj1 )
    {
        double t = x- obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator*(const A& obj1  )
    {
        double t = obj1.x*x;
        A temp;
        temp.x = t;
        return temp;
    }

    A operator/(const A& obj1)
    {
        double t = x/ obj1.x;
        A temp;
        temp.x = t;
        return temp;
    }

};


int main()
{
    A a1(4), a2(5);
    A a3 = a1+a2;
    A a4 = a1-a2;
    A a5 = a1*a2;
    A a6 = a1/a2;
    cout<<"Addition : "<<a3.getdata()<<endl;
    cout<<"Subtraction: "<<a4.getdata()<<endl;
    cout<<"Multiplication : "<<a5.getdata()<<endl;
    cout<<"Division : "<<a6.getdata()<<endl;

    return 0;
}
