#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Creating a Calculator using Inheritance :
// Idea :
/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and performs +, -, *, /, sqrt , reciprocal ,negative and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and performs any four scientific operations of your choice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using? -----> Multiple Inheritance  (But it can also be done by using Single Inheritance)
    Q2. Which mode of Inheritance are you using? ----> Public Mode in both base inheritances
    Q3. Create an object of HybridCalculator and display results of the simple and scientific calculator.
    Q4. How is code reusability implemented?
*/
// I would create this code by using single + multiple inheritance
//  Implementation :

class Simple_Calculator
{
private:
protected:
public:
    void sum(float, float);
    void mul(float, float);
    void minus(float, float);
    void divide(float, float);
    void recip(float);
    void neg(float);
    void sq(float);
};

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

class Scientific_Calculator
{

private:
    float result, rad;
    float si, co, ta;

protected:
public:
    void exponent(float, float);
    void trig(int);
    void logarithm(float);
    void mod(int, int);
};

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

class Full_Calculator : public Simple_Calculator, public Scientific_Calculator
{
private:
protected:
public:
};

// This could have been implemented as Simple inheritance as well

int main()
{
    while (1)
    {
        float x, y;
        int option;
        cout << "Enter the number for which operation you want to use : ";
        cout << endl
             << endl
             << " 1) Add Two Numbers." << endl;
        cout << " 2) Subtract Two Numbers." << endl;
        cout << " 3) Multipy Two Numbers." << endl;
        cout << " 4) Divide Two Numbers." << endl;
        cout << " 5) Reciprocal of a number." << endl;
        cout << " 6) Negative of a number." << endl;
        cout << " 7) Square Root of a number." << endl;
        cout << " 8) Modulus of Two Numbers." << endl;
        cout << " 9) Calculate Common Logarithm." << endl;
        cout << "10) Trigonometric Functions (Sin , Cos , Tan ) ." << endl;
        cout << "11) Calculate Power of a number." << endl
             << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Enter any other button except 1-11 to exit the program " << endl;

        cin >> option;

        switch (option)
        {
        case 1:
        {
            Full_Calculator obj;
            cout << "Enter two numbers for addition: " << endl;
            cin >> x >> y;
            obj.sum(x, y);

            break;
        }

        case 2:
        {
            Full_Calculator obj;
            cout << "Enter two numbers for subtraction : " << endl;
            cin >> x >> y;
            obj.minus(x, y);
            break;
        }
        case 3:
        {
            Full_Calculator obj;
            cout << "Enter two numbers for multiplication: " << endl;
            cin >> x >> y;
            obj.mul(x, y);
            break;
        }
        case 4:
        {
            Full_Calculator obj;
            cout << "Enter two numbers for division: " << endl;
            cin >> x >> y;
            obj.divide(x, y);
            break;
        }
        case 5:
        {
            Full_Calculator obj;
            cout << "Enter a number to calculate reciprocal except  zero : " << endl;
            cin >> x;
            obj.recip(x);
            break;
        }
        case 6:
        {
            Full_Calculator obj;
            cout << "Enter a number to calculate negative of : " << endl;
            cin >> x;
            obj.neg(x);
            break;
        }
        case 7:
        {
            Full_Calculator obj;
            cout << "Enter a number to calculate square root except negative numbers : " << endl;
            cin >> x;
            obj.sq(x);
            break;
        }
        case 8:
        {
            Full_Calculator obj;
            cout << "Enter two numbers for modulus : " << endl;
            cin >> x >> y;
            obj.mod(x, y);
            break;
        }
        case 9:
        {
            Full_Calculator obj;
            cout << "Enter a number to calculate Common Logarithm : " << endl;
            cin >> x;
            obj.logarithm(x);
            break;
        }
        case 10:
        {
            Full_Calculator obj;
            cout << "Enter a number to use Sin , Cos or Tan : " << endl;
            cin >> x;
            obj.trig(x);
            break;
        }
        case 11:
        {
            Full_Calculator obj;
            cout << "Enter two numbers , base first and exponent : " << endl;
            cin >> x >> y;
            obj.exponent(x, y);
            break;
        }

            // default:
            //     {
            //      cout<<"You exited the program . " <<endl;
            //   }
        }

        if (option != 1 & option != 2 & option != 3 & option != 4 & option != 5 & option != 6 & option != 7 & option != 8 & option != 9 & option != 10 & option != 11)
        {

            break;
        }

        char choice;
        cout << "Do you want to continue ? Press  (N or n) for No  and any other number for Yes : " << endl;
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            cout << "We are exiting this program" << endl;
            break;
        }
    }
    cout << "You exited the program . " << endl;

    return 0;
}
