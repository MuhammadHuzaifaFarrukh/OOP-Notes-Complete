#include <iostream>

using namespace std;

template <typename T>
void swapp(T &a, T &b )
{
    T temp = a;
    a=b;
    b= temp;
}

template <typename T1, typename T2>   //Or class or typename
T1 average(T1 a, T2 b)   //or T2
{
    return ((a+b)/2.0);
}

int main()
{
    float avg;
    float a =5,b=6;   // These data types will tell T1 and T2
    avg = average(a,b);
    cout<<"The average of the numbers is : "<<avg<<endl;

    int x=5,y=4.4;   // These data types will tell T1 and T2
    swapp(x,y);
    cout<<x<<endl<<y<<endl;

    return 0;
}
