#include "Scientific_Calculator.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Scientific_Calculator::exponent(float a, float b)
{
    result = pow(a, b);

    cout << a << " raised to power " << b << " is : " << setprecision(4) << fixed << result << endl
         << endl
         << endl;
}

void Scientific_Calculator::trig(int deg)
{
    int num;
    rad = (M_PI / 180.0) * deg; // Sin Cos Tan Functions work with Radians  , so first we convert input degrees into radians
    cout << "Press 1 for Sine , 2 for Cosine and 3 for Tangent Function " << endl
         << "To exit , please press any button other than 1,2,3 to exit the program " << endl;
    cin >> num;
    switch (num)
    {
    case 1:
    {
        si = sin(rad);
        cout << "The Sine of " << deg << " is : " << setprecision(4) << fixed << si << endl
             << endl
             << endl;
        break;
    }

    case 2:
    {
        co = cos(rad);
        cout << "The Cosine of " << deg << " is : " << setprecision(4) << fixed << co << endl
             << endl
             << endl;
        break;
    }

    case 3:
    {
        ta = tan(rad);
        cout << "The Tangent of " << deg << " is : " << setprecision(4) << fixed << ta << endl
             << endl
             << endl;
        break;
    }

    default:
    {
        cout << "The Program is Finished " << endl;
        exit(0);
        break;
    }
    }
}

void Scientific_Calculator::logarithm(float a)
{

    cout << "The log of " << a << " with base '10' " << " is : " << setprecision(4) << fixed << log10(a) << endl
         << endl
         << endl;
}

void Scientific_Calculator::mod(int a, int b)
{
    cout << "The modulus of " << a << " mod " << b << " is : " << setprecision(4) << fixed << (a % b) << endl
         << endl
         << endl;
}

