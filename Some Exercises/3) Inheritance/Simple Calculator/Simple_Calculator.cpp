#include <iostream>
#include <cmath>
#include <iomanip>
#include "Simple_Calculator.h"
using namespace std;

void Simple_Calculator::sum(float a, float b)
{

    cout << "The Sum of " << a << " and " << b << " is : " << setprecision(4) << fixed << (a + b) << endl
         << endl
         << endl;
}
void Simple_Calculator::mul(float a, float b)
{
    cout << "The Product of " << a << " and " << b << " is : " << setprecision(4) << fixed << (a * b) << endl
         << endl
         << endl;
}
void Simple_Calculator::minus(float a, float b)
{
    cout << "The Subtraction of " << a << " from " << b << " is : " << setprecision(4) << fixed << (a - b) << endl
         << endl
         << endl;
}
void Simple_Calculator::divide(float a, float b)
{
    cout << "The Division of " << a << " and " << b << " is : " << setprecision(4) << fixed << (a / b) << endl
         << endl
         << endl;
}

void Simple_Calculator::recip(float a)
{
    cout << "The Reciprocal of " << a << " is : " << setprecision(4) << fixed << (1.0 / a) << endl
         << endl
         << endl;
}

void Simple_Calculator::sq(float a)
{
    cout << "The Square Root of " << a << " is : " << setprecision(4) << fixed << sqrt(a) << endl
         << endl
         << endl;
}
void Simple_Calculator::neg(float a)
{
    cout << "The Negative of " << a << " is : " << setprecision(4) << fixed << (-(a)) << endl
         << endl
         << endl;
}

