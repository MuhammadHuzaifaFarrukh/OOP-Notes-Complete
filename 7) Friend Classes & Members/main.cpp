#include <iostream>

using namespace std;
class calculator;
class complex;
//Forward Declaration. Even if you don't use friend class or functions , using forward declaration won't do any error.
// Here calculator uses complex's data so we made it the friend of complex class .
//If we use friend class and put calculator above it , it needs forward declaration
// If we place complex above calculator in friend class , it does not need forward declaration
// If we place complex above calculator in friend functions only , then forward declaration.

class calculator
{
public :
    int add(int, int );
    int sumrealcomplex(complex &, complex &); // Use function prototype also
    int sumimagcomplex(complex &, complex &); //Using Object Reference might be more good
};

class complex
{
private:
    int a,  b;
public:
    void complex_no_display(int,int );

    //Individual Declaration of Functions as Friends
    //friend int calculator::sumrealcomplex(complex &,complex &);
    //friend int calculator::sumimagcomplex(complex &,complex &);

    //Aliter : Declaring the Entire class as friends
    friend class calculator;
    void print_numbers();

};


void complex::complex_no_display( int a1, int b1 )
{
    a=a1;
    b=b1;
}
void complex::print_numbers()
{
    cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
}



int calculator::sumrealcomplex(complex &o1, complex &o2)
{
    return (o1.a+o2.a);
}

int calculator::add(int a, int b)
{
    return (a+b);
}
int calculator::sumimagcomplex(complex &o1, complex &o2)
{
    return (o1.b+o2.b);
}

int main()
{
    complex c1,c2;
    c1.complex_no_display(1,4);
    c2.complex_no_display(3,5);
    calculator calc;
    int result1 = calc.sumrealcomplex(c1,c2);
    cout<<"The Sum of Real Parts is : "<<result1<<endl;
    int result2=calc.sumimagcomplex(c1,c2);
    cout<<"The Sum of Imaginary Parts is : "<<result2<<endl;

    return 0;
}
