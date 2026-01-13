#pragma once
#include <iostream>
#include <string>

using namespace std;


class Money
{
private:
    double amount;
    unsigned int currency_code = 0;   //By default every object currency is USD for easier use
    void copy_from(const Money&);
    double converter(const Money& , int); //To convert into USD , we multiply with their relative USD amount
    double converter_back(const Money& , int); //To convert from USD , we divide with their relative USD Amount

public:
    Money();
    Money(double , string);

    Money(const Money &);
    Money& operator=(const Money&);
    Money operator+(const Money&);
    Money operator-(const Money&);
    Money& operator+=(const Money&);
    Money& operator-=(const Money&);


    bool operator==(const Money&);
    bool operator<(const Money&);
    bool operator>(const Money&);
    bool operator<=(const Money&);
    bool operator>=(const Money&);
    bool operator!=(const Money&);

    void display(string); //This shows only the amount in the desired currency
    //We can make a function for details that shows that the object is in this amount for this currency

};
