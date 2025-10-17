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
    Complex c1 = Complex(4,6); //(Copy Epsilon , object b is constructed directly by calling the parameterized constructor in its final memory using the arg 4 and 6)
    // c1 = Complex(3,6); // (Use this only when you don't have any dynamically allocated data members , as it calls constructor and fills data into a new object and then calls compiler generated copy assignment operator which is never good when we have dynamically allocated data members)
    //Remember Constructor call is only done when object is created , not after its creation , as its done above , the created object above is a temporary created object which is then copied using compiler generated copy assingment code
    //Although compiler uses Copy Epsilon Method here for optimization , we may think as parameterized constructor and compiler generated copy constructor called here , though it did happen in older C++ versions)
    c1.printdata();

    Complex c2(5);
    c2.printdata();

    Complex c3;
    c3.printdata();
    return 0;
}
