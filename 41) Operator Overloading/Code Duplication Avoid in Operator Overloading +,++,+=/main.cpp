#include <chrono>
#include <iostream>
#include "Money.h"
#include "global.h"

#include "global.cpp"
#include "Money.cpp"

using namespace std;


int main()
{
    Money salary(1000, "USD");
    Money rent(200000, "PKR");
    Money bonus(500,  "EUR");
    Money total = salary + bonus;
    total -= rent;
    cout<<"After expenses : ";
    total.display("USD");
    cout<<endl;
    Money emergencyfunds(300, "GBP");
    if(total >= emergencyfunds )
    {
        cout<<"Enough funds for emergency "<<endl;
    }
    else
    {
        cout<<"Low Balance "<<endl;
    }
    Money copy = salary;
    if(copy == salary)
    {
        cout<<"Successful copy"<<endl;
    }
    cout<<"Total in PKR : "<<endl;
    total.display("PKR");


    //Also check from PKR to EUR not just from USD to others
    //Converter back is made just for the purpose that we need all currencies conversion

    return 0;
}
