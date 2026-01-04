#include <iostream>

using namespace std;

//Header files used for Exception Handling are : exception , stdexcept , new
//Exception Handling is done to catch the runtime errors in a system
//We can also catch them by if-else structure but that would be a terrible design
//This provides us a clean design.
//Runtime errors usually disturb the flow of program and exception occurs so we use exception handling to let program flow be undisturbed even if an exception occurs
//If we don't handle the exceptions then program is terminated abnormally and rest of the code is skipped that was after the exception occurred.
//In C++ , exception is an event or an object which is thrown at runtime. All exceptions are derived from std::exception class

//We implement it using : try, catch and throw blocks
//The Code which can throw exception is written inside the try block
//Then the code that leads to errors , that error/exception will be caught inside the catch block
//We can have multiple catch blocks to catch different types of exceptions and perform different actions when exceptions occur

//throw is used to throw exceptions to exception handler i.e it is used to communicate information about error
//A throw expression accepts one parameter and that parameter is passed to exception handler (catch block)
//A throw expression accepts one parameter and that parameter is passed to exception handler (catch block)
//throw statement is used when we want to throw an exception explicitly
//throw when executed stops all the flow and below code and searches for the nearest catch block (doesn't exit the function if it finds the catch block right there)
//throw has the type void , meaning we can use it like we want in an expression , so these things make it every different from an if-else statement

//Sometimes it may not accept arguments (Re-Throw)


int main()
{
    try
    {
        int x = -1;

        if (x < 0)
        {
            throw x;    //Throw Exception Manually
            cout<<"After Throw , Never Executed "<<endl;
        }
    }
    catch (int x)   //int that accepts the thrown exception by throw keyword
    {               //The catch block requires exact type match (like for string literals -> const char * , not just char* etc)
        cout<<"Exception Caught "<<endl;
    }

    cout << "After Exception , Program Continues "<<endl ;
    return 0;
}
