#include <iostream>
#include <cmath>
#include <iomanip>
#include "Simple_Calculator.h"
#include "Scientific_Calculator.h"
#include "Full_Calculator.h"
#include "Simple_Calculator.cpp"
#include "Scientific_Calculator.cpp"
#include "Full_Calculator.cpp"

using namespace std;

// Creating a Calculator using Inheritance :

// I would create this code by using single + multiple inheritance
// Can be also done using Single Inheritance , depends on your design
// If the 3rd class has extra functions then choose multiple inheritance
// If the new class has no extra function then we can choose single inheritance on the 2nd class

// Even though the 3rd class here has no extra function or things , we still choose to implement multiple inheritance to
// show use case and for a clean interface if the 3rd class may have extra functions in future use

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
