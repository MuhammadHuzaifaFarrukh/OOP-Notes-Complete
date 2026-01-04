#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
using namespace std;

//We throw exception inside a constructor to check if its given inputs are correct or not.
//We may do this in member initialization list , or inside constructor's body
//Here we show in constructor's member initialization list :
//This is also called function-try block
//we write try before : in constructor's member initialization list and this checks any wrong input or not
//The Body of B is executed and exception is thrown and gets caught in catch block
//Here the catch block implicitly throws an exception for which we have put try-catch block inside main as well
//As exception is thrown inside B's constructor , B object is never made and so destructor of A runs as well

class A
{
public:
    A()
    {
        cout << "A's constructor " << endl;
    }
    ~A()
    {
        cout << "A's destructor " << endl;
    }
};

class B : public A
{
public:
    // FUNCTION-TRY-BLOCK
    // The 'try' keyword is before the member initialization list
B() try :
        A()     //Will Check if any wrong input like nullptr for string type or any wrong input inside A's constructor
    {
        cout << "Inside B's constructor body." << endl;

        // 1. You MUST throw manually if you want to trigger an error here
        throw runtime_error("Critical failure in B!");
    }
    catch (const exception& e)
    {
        // 2. This block runs when the throw happens
        cout << "B's catch block: " << e.what() << endl;

        // 3. IMPLICIT RE-THROW:
        // Even though we don't write 'throw;', C++ does it for us here.
        // This is because B failed to build, so it cannot exist.
    }

    ~B()
    {
        cout << "B's destructor (this will never run!)" << endl;
    }
};

int main()
{
    cout << "--- Attempting to create object b1 ---" << endl;

    try
    {
        B b1; // This will fail
        cout << "This line will NEVER print." << endl;
    }
    catch (exception& e)
    {
        // 4. The automatic re-throw from B's constructor is caught here
        cout << "Main caught the re-thrown error: " << e.what() << endl;
    }

    cout << "--- Program continues after handling the failure ---" << endl;

    return 0;
}
