#include <iostream>

using namespace std;

class bank
{
private :

    int principal;
    int years;
    float return_value;
    float interest_Rate;

public :

    bank()
    {
        cout<<"HELLO";   //Its a blank constructor used to initialize member variables if they haven't been initialized yet.
    }

    bank(int p, int y, float r);
    bank(int p, int y, int r);
    void show();


};


bank::bank(int p,int y, float r)
{
    principal=p;
    years=y;
    interest_Rate=r;
    return_value = principal*(1+interest_Rate*years);
}
bank::bank(int p,int y, int r)
{
    principal=p;
    years=y;
    interest_Rate=  (float)r/100;
    return_value=principal;
    return_value = principal*(1+interest_Rate*years);
}

void bank::show()
{
    cout<<endl<<"Principal Amount was "<<principal<<endl
        <<"Return Value after "<<years<<" years is " << return_value<<endl;

}

int main()
{

    int p, y, R;   // Objects are not initialized yet
    float r;
    cout<< "Enter your Principal Amount : ";
    cin>>p;
    cout<< "Enter your number of years : ";
    cin>>y;
    cout<< "Enter your interest Rate like 0.01 for 1% : ";
    cin>>r;
    bank person1 = bank(p,y,r); // Dynamic Initialization (Runtime Initialization)
    person1.show();

    cout<< "Enter your Principal Amount : ";
    cin>>p;
    cout<< "Enter your number of years : ";
    cin>>y;
    cout<< "Enter your interest Rate like 1 for 1% : ";
    cin>>R;
    bank   person2 = bank(p,y,R);
    person2.show();

    return 0;
}










/*
class Complex
{
private:
    int a,b;
public :
    Complex(){}  // There's no need to write a blank constructor if already Complex(); function has been used somewhere else
    Complex(int , int);
    Complex(int );

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


void Complex::printdata()
    {
        cout<<"Your number is : " <<a<< " + "<<b<<"i"<<endl;
    }
int main()
{
    Complex c1,c2;
    c1=Complex(3,6);
    c1.printdata();

   c2=Complex(9);
    c2.printdata();


    return 0;
}
*/
