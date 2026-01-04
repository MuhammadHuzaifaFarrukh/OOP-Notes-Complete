#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
using namespace std;

int main()
{
    //std::string class has a try function-block inside its constructor that prevents it from bad initialization
    //nullptr cannot be assigned to a string (for a pointer only) so it throws exception inside its constructor which is caught here inside main's block
    try
    {
        string s = nullptr;
    }
    catch(exception &e)
    {
        cout<<e.what();
    }


    return 0;
}
