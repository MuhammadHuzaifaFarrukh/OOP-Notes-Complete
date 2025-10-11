#include <iostream>
#include <iomanip>
using namespace std;


//Just like Function Overloading
//Also beware of errors if you use constructor overloading with default arguments

class Complex
{
private:
    int a,b;
public :
    Complex(int, int);
    Complex(int );
    Complex();

    void printdata();
};

Complex::Complex(int x,int y)
{
    a=x;
    b=y;
}

Complex::Complex(int x)
{
    a=x;
    b=0;
}

Complex::Complex()
{
    a=0;
    b=9;
}

void Complex::printdata()
{
    cout<<"Your number is : " <<a<< " + "<<b<<"i"<<endl;
}
int main()
{
    Complex c1 = Complex(4,6);
    // c1 = Complex(3,6); // Explicit Call when changing values
    // Implicit Call will not work for this purpose
    c1.printdata();

    Complex c2(5);
    c2.printdata();

    Complex c3;
    c3.printdata();
    return 0;
}
