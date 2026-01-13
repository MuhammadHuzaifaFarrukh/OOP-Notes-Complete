#pragma once
#include <iostream>

using namespace std;

class Rational
{
    private :
    int numerator;
    int denominator;

    public :
    Rational();
    Rational(int num , int den);
    void show() const;
    Rational operator+(const Rational &r);
    Rational& operator-=(const Rational &r);
    Rational operator*(const Rational &r);

    bool operator==(const Rational &r);
    Rational& operator++();
    Rational operator++(int x);
    Rational& operator*(int x);
    Rational& operator/=(int x);
    Rational& operator/=(const Rational &r);

};

