#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational() {}
Rational::Rational(int num, int den)
{
    if (den == 0)
    {
        cout << "Denomicator cannot be zero." << endl;
    }
    else
    {
        numerator = num;
        denominator = den;
    }
}

void Rational::show() const
{
    cout << "Rational Number: " << numerator << "/" << denominator << endl;
}

//Makes seaparte copies and returns the copy that can be stored in another object
Rational Rational::operator+(const Rational &r)
{
    Rational temp;
    temp.numerator= numerator * r.denominator + r.numerator * denominator;
    temp.denominator = denominator * r.denominator;
    return temp;
}

//Modifies the current object and returns its reference
Rational& Rational::operator-=(const Rational &r)
{
    numerator = numerator * r.denominator - r.numerator * denominator;
    denominator = denominator * r.denominator;
    return *this;
}

Rational Rational::operator*(const Rational &r)
{
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    return Rational(num, den);
    //We can do this by creating an another object , and use its temp data and return that one like we did in + function but above line is also fine
    //This one uses constructor and makes an object of Rational and returns it.
}



bool Rational::operator==(const Rational &r)
{
    //This checks cross multiplication to avoid floating point precision issues
    return (numerator * r.denominator == r.numerator * denominator);
}

//Prefix increment operator
//Modifies the current object and returns its reference
// ++a , so first addition is done and object is modified and then reference is returned
Rational& Rational::operator++()
{
    numerator += denominator;
    return *this;

}


//Postfix increment operator
//Makes a copy of current object, modifies the current object and returns the copy made before modification
// a++ , so first copy is made of current object, then addition is done and object is modified, finally the copy made before modification is returned
Rational Rational::operator++(int x)
{
    Rational temp = *this; //Make a copy of current object
    numerator += denominator; //Increment the current object
    return temp; //Return the copy made before increment
}

Rational& Rational::operator*(int x)
{
    numerator = numerator * x;
    return *this;
}

Rational& Rational::operator/=(int x)
{
    denominator = denominator * x;
    return *this;
}


Rational& Rational::operator/=(const Rational &r)
{
    numerator = numerator * r.denominator;
    denominator = denominator * r.numerator;
    return *this;
}

