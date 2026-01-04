#include <iostream>

using namespace std;

//If there is no catch for the exception then the program terminates abnormally and crashes
//It calls the std::terminate() which by default calls std::abort()
//You may see a message like :
//terminate called after throwing an instance of 'int' (or whatever the data type required)

int main()
{
    try
    {
        throw 'a';      //This is a character or a character constant
    }
    catch(int c)
    {
        cout<<"Caught a character exception "<<c<<endl;
    }

    return 0;
}
