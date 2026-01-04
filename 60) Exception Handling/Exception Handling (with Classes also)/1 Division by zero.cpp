#include <iostream>

using namespace std;

//Now we learn how to throw exceptions to exception objects
//We know that there is a class of exception inside std::exception
//All the other classes like : runtime_error , logic_error then inherit this exception class

//Try to Catch Exceptions by Reference , not by value as it breaks the polymorphism and does object slicing which will not be beneficial
//We throw the child class object i.e runtime_error or any other objects and these are passed to the catch block
//Inside catch block , we have the exception & object that will provide set up for runtime polymorphism
//As we call e.what() function , due to runtime polymorphism , this e.what() is executed from the Child class instead of exception class

//Each class object that we pass , has a constructor , to whom we can pass our message of const char* type or a string
// .what() function has prototype : virtual const char* what() const noexcept{...}
int main()
{
    try
    {
        int x = 10, y = 0;

        if (y == 0)
        {
            // We throw an OBJECT of class runtime_error
            throw runtime_error("Mathematical Error: Attempted to divide by zero!");
        }
        cout << x / y << endl;
    }
    catch ( exception& e)   //or const exception & e
    {
        // We catch by reference to the parent class 'exception'
        // .what() is a method that returns the string we provided above
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}
