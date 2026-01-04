#include <iostream>
#include <stdexcept>

using namespace std;

//You can re-throw an exception
//Here when we throw an exception in our function , another exception is thrown inside the catch block
//This will then find the final catch block inside main() and complete program

//throw without any arguments is called re-throw and it must be done after we have done throw once with parameters
//so that the same object to throw the again is identified correctly
//throw without any arguments tells compiler to throw the currently active exception object

int processDatabase()
{
    try
    {
        // Imagine a database error occurs here
        throw runtime_error("Database Connection Lost");
    }
    catch (runtime_error& e)
    {
        // PARTIAL HANDLING
        cout << "Log: An error occurred in the DB layer: " << e.what() << endl;

        // RETHROW: Send the exact same error to the caller
        throw;
    }
    return 100;
}

int main()
{
    try
    {
        processDatabase();
    }
    catch (exception& e)
    {
        // FINAL HANDLING
        cout << "Main: Notified of error. Closing program safely... " << e.what() << endl;
    }
    return 0;
}
