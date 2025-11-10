#include <iostream>
using namespace std;

// Here we can observe Polymorphism in 2 different ways
// 1) Compile time polymorphism of >> or << operators
// 2) Binding of cout to ostream objects due to which Internal Base Buffers are being pointed to
// Base / Derived & References (Runtime Polym)

class A
{
private:
    double x;
public:
    A(double s)
    {
        x = s;
    }
    double getdata() const
    {
        return x;
    }
    void setdata(double s)
    {
        x = s;
    }
};

// Without friend function
ostream& operator<<(ostream& os, const A& obj)  // (Polymorphism when cout is passed here , ostream gets the buffer of cout)
{
    os << obj.getdata();
    return os;
}

istream& operator>>(istream& is, A& obj) //(Polymorphism when cin is passed here , istream gets the buffer of cin)
{
    double temp;
    is >> temp;
    obj.setdata(temp);
    return is;
}

int main()
{
    A a1(4.5);
    cout << "Value: " << a1 << endl;

    cout << "Enter new value: ";
    cin >> a1;
    cout << "New value: " << a1 << endl;

    return 0;
}

/*
    When you declare a generic stream object without a buffer pointer (e.g., std::istream is;), the object is created, but its internal pointer accessed by rdbuf() is typically null or points to a default disconnected state. It is not ready for I/O.
    This is why, to make a generic stream usable for standard I/O, you have to manually provide a buffer pointer using the constructor:
*/

//We can take input output using istream and ostream objects by redirecting their buffer to cin and cout objects
//We can also read/write from file if we redirect their buffer to the file's pointer of ifstream and ofstream objects
//We can also use std::cout and redirect buffer so that it will be used to output in the file

//Also for operator overloading for stream operators , we don't use rdbuf because we pass cout and cin as references so they already have rdbuf as cin and cout (Polymorphism)
